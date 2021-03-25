//Author: Mark McMurtury

import { Component,OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { EntryService } from '../entry.service';

import * as firebase from 'firebase';
@Component({
  selector: 'app-tab1',
  templateUrl: 'tab1.page.html',
  styleUrls: ['tab1.page.scss']
})
export class Tab1Page {
	user:any = null;
	
  UserID = firebase.auth().currentUser.uid;
  constructor(
	private router: Router,
  public entryService: EntryService,
 
  ) { }
	
	ngOnInit(){
    this.entryService.clearList();
    firebase.auth().setPersistence(firebase.auth.Auth.Persistence.LOCAL)
  .then(function() {
    // Existing and future Auth states are now persisted in the current
    // session only. Closing the window would clear any existing state even
    // if a user forgets to sign out.
    // ...
    // New sign-in will be persisted with session persistence.
    console.log("##########################################################################################################")
  })
  .catch(function(error) {
    // Handle Errors here.
    var errorCode = error.code;
    var errorMessage = error.message;
  });
    this.user = this.entryService.getUser();
    console.log("Getting user.");
	}
	
	addEntryPage(){
    console.log("Add Entry");
    this.router.navigate(["/create-entry"]);
  }
}
