import { Injectable } from "@angular/core";
import * as firebase from 'firebase/app';
import { AngularFireAuth } from '@angular/fire/auth';



@Injectable({
  providedIn: 'root'
})
export class AuthService {
  
  constructor(
		public afAuth: AngularFireAuth
  ){}
  
  doRegister(email, password){
   return new Promise<any>((resolve, reject) => {
     firebase.auth().createUserWithEmailAndPassword(email, password)
     .then(   
      res =>{ resolve(res),this.doLogin(email,password)
      }, 
       err => reject(err))
   })
  }

  doLogin(email, password){
    firebase.auth().setPersistence(firebase.auth.Auth.Persistence.LOCAL)
  .then(function() {
    // Existing and future Auth states are now persisted in the current
    // session only. Closing the window would clear any existing state even
    // if a user forgets to sign out.
    // ...
    // New sign-in will be persisted with session persistence.
    console.log("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
    return firebase.auth().signInWithEmailAndPassword(email, password);
  })
  .catch(function(error) {
    // Handle Errors here.
    var errorCode = error.code;
    var errorMessage = error.message;
  });
   return new Promise<any>((resolve, reject) => {
     firebase.auth().signInWithEmailAndPassword(email, password)
      .then(
        res => resolve(res),
        err => reject(err))
   })
  }

	doLogout(){
    return new Promise<any>((resolve, reject) => {
      this.afAuth.auth.signOut()
       .then(  
         res => resolve(res),
         err => reject(err))
     })
  }
  doForgotPassword(email){
    return new Promise<any>((resolve, reject) => {
      this.afAuth.auth.sendPasswordResetEmail(email)
       .then(  
         res => resolve(res),
         err => reject(err))
     })
  }
}
