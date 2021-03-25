package osp.Ports;

import java.util.*;
import osp.IFLModules.*;
import osp.Threads.*;
import osp.Tasks.*;
import osp.Memory.*;
import osp.Utilities.*;

/**
 The studends module for dealing with ports. The methods 
 that have to be implemented are do_create(), 
 do_destroy(), do_send(Message msg), do_receive(). 
 
 
 @OSPProject Ports
 */

public class PortCB extends IflPortCB {
  private int bufferIn;
  private int bufferOut;
 
  public PortCB() {

    super();
    
  }
  
  /**
   This method is called once at the beginning of the
   simulation. Can be used to initialize static variables.
   
   @OSPProject Ports
   */
  public static void init()
  {
    // your code goes here
    
  }
  
  /** 
   Sets the properties of a new port, passed as an argument. 
   Creates new message buffer, sets up the owner and adds the port to 
   the task's port list. The owner is not allowed to have more 
   than the maximum number of ports, MaxPortsPerTask.
   
   @OSPProject Ports
   */
  public static PortCB do_create() {
    TaskCB currTask = null;
    PortCB port = new PortCB(); //Create new PortCB object
    try {
      currTask = MMU.getPTBR().getTask(); //get current task
    } catch (NullPointerException e) { }
    
    int curr = currTask.getPortCount();
    //verify current task does not already have max ports allowed
    if(curr >= MaxPortsPerTask) {
      return null;
    }
    //assign PortCB object to current task
    if(currTask.addPort(port) == FAILURE) {
      return null;
    }
    port.setTask(currTask); //currTask owns PortCB object
    port.setStatus(PortLive);
    port.bufferIn = 0; //initialize state of the port's message buffer
    port.bufferOut = 0;
    return port;
  }
  
  /** Destroys the specified port, and unblocks all threads suspended 
    on this port. Delete all messages. Removes the port from 
    the owners port list.
    @OSPProject Ports
    */
  public void do_destroy() {
    this.setStatus(PortDestroyed); 
    this.notifyThreads();
    this.getTask().removePort(this); //remove port from Task's table of active ports
    this.setTask(null); //set owner of port to null
  }
  
  /**
   Sends the message to the specified port. If the message doesn't fit,
   keep suspending the current thread until the message fits, or the
   port is killed. If the message fits, add it to the buffer. If 
   receiving threads are blocked on this port, resume them all.
   
   @param msg the message to send.
   
   @OSPProject Ports
   */
  public int do_send(Message msg) {
    //verify that the message to be sent is well-formed
    if(msg == null || (msg.getLength() > PortBufferLength)) {
      return FAILURE;
    }
    TaskCB currTask = null;
    ThreadCB currThread = null;
    SystemEvent event0 = new SystemEvent("Suspended");  //Create new system event
    try {
      currThread = MMU.getPTBR().getTask().getCurrentThread(); //get current thread
    } catch (NullPointerException e) { }
    int bufferRoom;
    currThread.suspend(event0);
    boolean suspendMessage = true;
    while(suspendMessage == true) {
      if(this.bufferIn < bufferOut) {
        bufferRoom = this.bufferOut - this.bufferIn; //Gets available buffer room
      }
      else if(this.bufferOut == this.bufferIn) {
        if(this.isEmpty()) {
          bufferRoom = PortBufferLength; //Sets buffer room to length of empty port
        } else {
          bufferRoom = 0; //No room in buffer
        }
      } else {
        bufferRoom = (this.bufferOut-this.bufferIn) + PortBufferLength;
      }
      if(msg.getLength() <= bufferRoom) {
        suspendMessage = false; //Cannot Suspend
      } else {
        currThread.suspend(this); //Suspend Message
      }
      if(currThread.getStatus() == ThreadKill) {
        this.removeThread(currThread);
        return FAILURE;
      }
      if(this.getStatus() != PortLive) {
        event0.notifyThreads();
        return FAILURE;
      }
    }
    this.appendMessage(msg); //insert message into port buffer
    this.notifyThreads();
    this.bufferIn = (this.bufferIn + msg.getLength()) % PortBufferLength; //update free space in buffer
    event0.notifyThreads();
    return SUCCESS;
  }
  
  /** Receive a message from the port. Only the owner is allowed to do this.
    If there is no message in the buffer, keep suspending the current 
    thread until there is a message, or the port is killed. If there
    is a message in the buffer, remove it from the buffer. If 
    sending threads are blocked on this port, resume them all.
    Returning null means FAILURE.
    
    @OSPProject Ports
    */
  public Message do_receive() {
    TaskCB task1 = null;
    ThreadCB thread1 = null;
    try {
      task1 = MMU.getPTBR().getTask();
      thread1 = task1.getCurrentThread(); //get current thread
    } catch (NullPointerException e) {     }
    
    //check if task that owns thread also owns port
    if(task1 != this.getTask()) {
      return null;
    }
    
    SystemEvent event1 = new SystemEvent("received"); //Create SystemEvent object
    thread1.suspend(event1);
    boolean suspendedMessage = true;
    while(suspendedMessage == true) {
//If port buffer is empty
      if(this.isEmpty()) {
        thread1.suspend(this);
      } else {
        suspendedMessage = false; //no message suspended if not empty
      }
      if(thread1.getStatus() == ThreadKill) {
        this.removeThread(thread1);
        event1.notifyThreads();
        return null;
      }
      if(this.getStatus() != PortLive) {
        event1.notifyThreads();
        return null;
      }
    }
    Message message1 = this.removeMessage(); //Gets the message object
    this.bufferOut = (this.bufferOut + message1.getLength()) % PortBufferLength; //update length of buffer
    this.notifyThreads();
    event1.notifyThreads();
    return message1;
  }
  
  /** Called by OSP after printing an error message. The student can
    insert code here to print various tables and data structures
    in their state just after the error happened.  The body can be
    left empty, if this feature is not used.
    
    @OSPProject Ports
    */
  public static void atError()
  {
    // your code goes here
    
  }
  
  /** Called by OSP after printing a warning message. The student
    can insert code here to print various tables and data
    structures in their state just after the warning happened.
    The body can be left empty, if this feature is not used.
    
    @OSPProject Ports
    */
  public static void atWarning()
  {
    // your code goes here
    
  }
  
  
  /*
   Feel free to add methods/fields to improve the readability of your code
   */
  
}

/*
 Feel free to add local classes to improve the readability of your code
 */
