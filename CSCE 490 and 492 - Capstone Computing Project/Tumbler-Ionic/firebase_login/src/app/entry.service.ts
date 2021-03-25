
//Author: Mark McMurtury

import { Injectable, Query } from '@angular/core';
import * as firebase from 'firebase';
import { resolve } from 'url';
//import { Storage } from '@ionic/storage';

@Injectable({
  providedIn: 'root'
})
export class EntryService {
	public falls:Array<any> = [
//	{"date":"2020-02-14", "time":2, "timep":"P.M.", "injury":true, "requriedMed":false,  "serverty":3, "description":"Fell while typing"},
//	{"date":"2020-02-14", "time":3, "timep":"P.M.", "injury":false, "requriedMed":false,  "serverty":3, "description":"Fell while typing"}
	];

	public pFalls:Array<any> = [
		
	];
	
	

	public user:any = {
		"userID":"0001",
		"userName":"Tester",
		"UID":this.getUID(),
		"name" : this.getName(),  
		"role":this.getRole()

	};

  constructor() { }

  clearList(){
	this.falls= [];
  }

  getUID(){
	  return firebase.auth().currentUser.uid;
  }

  getName(){
	  return firebase.auth().currentUser.displayName;
  }
  //Get whether it is a doctor or not.
  getRole(){
	  return this.getDoc();
  }


  getDoc() { 
	var isAC = false;
  var db = firebase.firestore().collection("roles").doc(this.getUID());
  db.get().then(function(doc) {
	  if(doc.exists){
		  console.log(doc.data());
		  isAC = doc.get("doctor");
		  console.log(isAC);
	  }
	  else{

	  }
	  return isAC;
  })
}

  

	
  getAllItems(falls) {
	return new Promise((resolve, reject) => {
	  firebase.firestore().collection("users").doc(this.getUID()).collection("entries")
		.get()
		.then((querySnapshot) => {
		  let arr = [];
		  console.log(querySnapshot);
		  querySnapshot.forEach(function(doc) {
			var obj = JSON.parse(JSON.stringify(doc.data()));
			obj.id = doc.id;
			//obj.eventId = doc.id;
			arr.push(obj);
			falls.push(obj);
			console.log(obj);
		  });
	
		  if (arr.length > 0) {
			resolve(arr);
		  } else {
			console.log("No such document!");
			resolve(null);
		  }
		})
		.catch((error: any) => {
		  reject(error);
		});
	   });
	  }
	  
	  getThings(UID, falls) {
		  let self = this;
		  console.log(UID);
		  let path: string = "users/"+UID+"/entries/";
		  console.log(path);
		return new Promise((resolve, reject) => {
	  firebase.firestore().collection(path)
		.get()
		.then((querySnapshot) => {
			console.log(UID);
			console.log(querySnapshot);
		  let arr = [];
		  querySnapshot.forEach(function(doc) {
			console.log(doc);
			var obj = JSON.parse(JSON.stringify(doc.data()));
			obj.id = doc.id;
			console.log(obj.id);
			//obj.eventId = doc.id;
			arr.push(obj);
			falls.push(obj);
			//self.falls.push(obj);
			console.log(obj);
		  });
	
		  if (arr.length > 0) {
			resolve(arr);
		  } else {
			console.log("No such document!");
			resolve(null);
		  }
		})
		.catch((error: any) => {
		  reject(error);
		});
	   });
	  }

	getFallArr(){
		return this.falls;
	}

  getFalls(){
	  console.log("00000000000000000000000000000000000000000")
	  this.getAllItems(this.falls);
	  return this.falls;
  }
  getUser(){
	  return this.user;
  }
  addEntry(date, time, timep, injury, requriedMed, serverty, description){
	  this.falls.push({
		  'date':date,
		  'time':time,
		  'timep':timep,
		  'injury':injury,
		  'requriedMed':requriedMed,
		  'serverty':serverty,
		  'description':description
	  });
	  firebase.firestore().collection("users").doc(this.getUID()).collection("entries").add({
		'date':date,
		'time':time,
		'timep':timep,
		'injury':injury,
		'requriedMed':requriedMed,
		'serverty':serverty,
		'description':description
	  })
  }

}

