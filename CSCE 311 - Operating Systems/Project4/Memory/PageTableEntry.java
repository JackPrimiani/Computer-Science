package osp.Memory;

import osp.Hardware.*;
import osp.Tasks.*;
import osp.Threads.*;
import osp.Devices.*;
import osp.Utilities.*;
import osp.IFLModules.*;
/**
 The PageTableEntry object contains information about a specific virtual
 page in memory, including the page frame in which it resides.
 
 @OSPProject Memory
 
 */

public class PageTableEntry extends IflPageTableEntry {
  /**
   The constructor. Must call
   
   super(ownerPageTable,pageNumber);
   
   as its first statement.
   
   @OSPProject Memory
   */
  
  boolean pageFaulted = false;
  
  public PageTableEntry(PageTable ownerPageTable, int pageNumber) {
    super(ownerPageTable, pageNumber);
  }
  
  /**
   This method increases the lock count on the page by one. 
   
   The method must FIRST increment lockCount, THEN  
   check if the page is valid, and if it is not and no 
   page validation event is present for the page, start page fault 
   by calling PageFaultHandler.handlePageFault().
   
   @return SUCCESS or FAILURE
   FAILURE happens when the pagefault due to locking fails or the 
   that created the IORB thread gets killed.
   
   @OSPProject Memory
   */
  public int do_lock(IORB iorb) {
    ThreadCB thread = iorb.getThread();
    if(!isValid()) { 
      if(getValidatingThread() == null) {
        PageFaultHandler.handlePageFault(thread, GlobalVariables.MemoryLock, this); //initiate page fault handler
      } else {   
        if(getValidatingThread() != thread) {
          thread.suspend(this); // suspend pagefault
          if(thread.getStatus() == GlobalVariables.ThreadKill) {
            return GlobalVariables.FAILURE; // return failure if thread is to be killed
          }
        }
      }
    }
    /*
     threads waiting on the page will be unblocked
     by the pagefault handler
     */
    /*
     increment the lock count of the frame associated with the page
     */ 
    
    getFrame().incrementLockCount();
    return GlobalVariables.SUCCESS;
  }
  
  /** This method decreases the lock count on the page by one. 
    * 
    This method must decrement lockCount, but not below zero.
    
    @OSPProject Memory
    */
  public void do_unlock() {
    getFrame().decrementLockCount();
  }
  
  
  /*
   Feel free to add methods/fields to improve the readability of your code
   */
  
}

/*
 Feel free to add local classes to improve the readability of your code
 */
