/*
 * 
 Author: Jack Primiani
 Email: primiani@email.sc.edu
 */
package osp.Threads;
import java.util.Vector;
import java.util.Enumeration;
import java.util.ArrayList;
import osp.Utilities.*;
import osp.IFLModules.*;
import osp.Tasks.*;
import osp.EventEngine.*;
import osp.Hardware.*;
import osp.Devices.*;
import osp.Memory.*;
import osp.Resources.*;

/**
   This class is responsible for actions related to threads, including
   creating, killing, dispatching, resuming, and suspending threads.

   @OSPProject Threads
*/
public class ThreadCB extends IflThreadCB {
  static Vector<ThreadCB> threadlist;
  public ThreadCB() {
        super();
    }

    /**
       This method will be called once at the beginning of the
       simulation. The student can set up static variables here.
       
       @OSPProject Threads
    */
    public static void init() {
        // array made for thread queue
        threadlist = new Vector<ThreadCB>();
    }

    /** 
        Sets up a new thread and adds it to the given task. 
        The method must set the ready status 
        and attempt to add thread to task. If the latter fails 
        because there are already too many threads in this task, 
        so does this method, otherwise, the thread is appended 
        to the ready queue and dispatch() is called.

 The priority of the thread can be set using the getPriority/setPriority
 methods. However, OSP itself doesn't care what the actual value of
 the priority is. These methods are just provided in case priority
 scheduling is required.

 @return thread or null

        @OSPProject Threads
    */
    static public ThreadCB do_create(TaskCB task) {
        if(task.getThreadCount()>= MaxThreadsPerTask){
            dispatch();
            return null;
        }    // make sure the task already have the max # of threads
        ThreadCB newThread = new ThreadCB(); 
        newThread.setPriority(task.getPriority());
        newThread.setStatus(ThreadReady);
        newThread.setTask(task);    // Associate the task with the thread
        if(task.addThread(newThread) != SUCCESS){
            dispatch();
            return null;
        }
        threadlist.add(newThread);    //  Append new thread to readyqueue
        dispatch();
        return newThread;
    }
    

    /** 
 Kills the specified thread. 

 The status must be set to ThreadKill, the thread must be
 removed from the task's list of threads and its pending IORBs
 must be purged from all device queues.
        
 If some thread was on the ready queue, it must removed, if the 
 thread was running, the processor becomes idle, and dispatch() 
 must be called to resume a waiting thread.
 
 @OSPProject Threads
    */
    public void do_kill() {
        int currentStatus = getStatus(); // Get status of thread
        setStatus(GlobalVariables.ThreadKill); //For ready state thread
        if (currentStatus == GlobalVariables.ThreadReady) {  
            threadlist.remove(this);
        } //Remove from ready queue
        if (currentStatus == GlobalVariables.ThreadRunning) {  //If thread status is ThreadRunning then preempt it
            setStatus(GlobalVariables.ThreadKill);
            getTask().setCurrentThread(null);
            MMU.setPTBR(null);
        }
        //Remove the task from the thread
        TaskCB task = getTask();
        task.removeThread(this);
        for (int id = 0; id < Device.getTableSize(); id ++) {
            Device.get(id).cancelPendingIO(this);
        }
        //Release all resources
        ResourceCB.giveupResources(this);
        // Check if the task has any threads left. If not, then invoke the Task kill() method to kill the task. 
        if (getTask().getThreadCount() == 0) {
            getTask().kill();
        }
        ThreadCB.dispatch();
    }
      /** Suspends the thread that is currenly on the processor on the 
        specified event. 

        Note that the thread being suspended doesn't need to be
        running. It can also be waiting for completion of a pagefault
        and be suspended on the IORB that is bringing the page in.
 
 Thread's status must be changed to ThreadWaiting or higher,
        the processor set to idle, the thread must be in the right
        waiting queue, and dispatch() must be called to give CPU
        control to some other thread.

 @param event - event on which to suspend this thread.

        @OSPProject Threads
    */
    public void do_suspend(Event event) {
        int status = this.getStatus();
        if( status == ThreadRunning){     //if the thread is running, update the status to waiting
            setStatus(ThreadWaiting);
            this.getTask().setCurrentThread(null);  //set the current thread as null
        } else if(status >= ThreadWaiting){    //if thread is already waiting, update the status by one level
            setStatus(status+1);
        }
        threadlist.remove(this);      //remove the thread from the ready queue
        event.addThread(this);       //add the thread to the waiting queue
        dispatch();
    }

    /** Resumes the thread.
        
 Only a thread with the status ThreadWaiting or higher
 can be resumed.  The status must be set to ThreadReady or
 decremented, respectively.
 A ready thread should be placed on the ready queue.
 
 @OSPProject Threads
    */
    public void do_resume() {
        int status = getStatus();
        if(status == ThreadWaiting){     //if the thread is waiting at level one put it into the ready queue
            setStatus(ThreadReady);
            threadlist.add(this);
        } else{
            setStatus(status - 1);      //if thread is waiting at higher level, decrease its wait state
        }
        dispatch();
    }

    /** 
        Selects a thread from the run queue and dispatches it. 

        If there is just one theread ready to run, reschedule the thread 
        currently on the processor.

        In addition to setting the correct thread status it must
        update the PTBR.
 
 @return SUCCESS or FAILURE

        @OSPProject Threads
    */
    public static int do_dispatch() {
        TaskCB task = null;
        TaskCB task2 = null;
        ThreadCB thread = null;
        ThreadCB newThread = null;
        try{  
            task = MMU.getPTBR().getTask();    //get the current task
            thread = task.getCurrentThread();   //get the current thread
        } catch(Exception e) {}
        if(thread != null) {        //free the resources and CPU from the running thread
            task.setCurrentThread(null);    //set the currrent thread as null
            thread.setStatus(ThreadReady);    //change the status of running thread to ready
            MMU.setPTBR(null);
            threadlist.add(thread);      //add the thread to ready queue
        }
        if(threadlist.size()>0) {      //call the new thread to start execution
            newThread = threadlist.remove(0);   //take the first thread from ready queue
            MMU.setPTBR(newThread.getTask().getPageTable());
            task2 = newThread.getTask();
            task2.setCurrentThread(newThread);
            newThread.setStatus(ThreadRunning);
            HTimer.set(50);       // Since using RR scheduling, set the interrupt timer using a quantum of 50
            return SUCCESS;
        }
        MMU.setPTBR(null);
        return FAILURE;
    }

    /**
       Called by OSP after printing an error message. The student can
       insert code here to print various tables and data structures in
       their state just after the error happened.  The body can be
       left empty, if this feature is not used.

       @OSPProject Threads
    */
    public static void atError() {
       
    }

    /** Called by OSP after printing a warning message. The student
        can insert code here to print various tables and data
        structures in their state just after the warning happened.
        The body can be left empty, if this feature is not used.
       
        @OSPProject Threads
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
