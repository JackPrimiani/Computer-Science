import { Component, OnInit } from '@angular/core';
import { Router,Routes, RouterModule } from '@angular/router';
import { Validators, FormBuilder, FormGroup, FormControl } from '@angular/forms';
import { AuthService } from '../services/auth.service';
import { AngularFireAuth, AngularFireAuthModule } from '@angular/fire/auth';
import { AngularFireModule } from '@angular/fire';
import * as firebase from 'firebase';
import { AlertController } from '@ionic/angular';


@Component({
  selector: 'app-login',
  templateUrl: './login.page.html',
  styleUrls: ['./login.page.scss'],
  providers: [AuthService, AngularFireAuth, AngularFireModule],
})
export class LoginPage implements OnInit {
  validations_form: FormGroup;
  errorMessage: string = '';
  password = "";
  email = "";


  constructor(
  private authService: AuthService,
	private router: Router,
	private alertCtrl: AlertController
	) { }

  ngOnInit() {
    firebase.auth().onAuthStateChanged(user => {
      if(user){
      var isAC = false;
 let self = this;
 var db = firebase.firestore().collection("roles").doc(firebase.auth().currentUser.uid);
 db.get().then(function(doc)  {
   console.log(doc.data());
   isAC = doc.get("doctor");
   console.log(isAC);
   if(isAC==true)
   self.router.navigate(["/doctortabs"]);
   else
   self.router.navigate(["/tabs"]);
 })
};
    })
}

  
  tryLogin(email,password){
    return firebase.auth().setPersistence(firebase.auth.Auth.Persistence.LOCAL)
      .then( () => {
         firebase.auth().signInWithEmailAndPassword(email, password).then(res =>{
         },err => {
          this.errorMessage = err.message;
          console.log(err)
          this.warning(err);
         })
         this.password ="";
         firebase.auth().onAuthStateChanged(user => {
           if(user){
           var id = firebase.auth().currentUser.uid;
         var isAC = false;
    let self = this;
    var db = firebase.firestore().collection("roles").doc(id);
		db.get().then(function(doc)  {
			console.log(doc.data());
			isAC = doc.get("doctor");
      console.log(isAC);
      if(isAC==true)
      self.router.navigate(["/doctortabs"]);
      else
      self.router.navigate(["/tabs"]);
    })
         }});
      }).catch(err => {
        this.warning(err);
        return Promise.reject(err);
        
      })
  }
  
	async warning(err){
		const alert = await this.alertCtrl.create({
		  header: 'Error',
		  message: err,
		  buttons: [
			{ text: 'Okay' }
		  ]
	  });
	  await alert.present();
	}
   
  signup(){
  	this.router.navigate(["/signin"]);
  }

  async forgotPassword(){
    let alert = await this.alertCtrl.create({
      message: 'Enter email',
      inputs: [{
        name: 'email',
        placeholder: 'Email',
        type: 'email'
      }],
      buttons: [{
        text: 'Send Password reset',
        handler: data => {
          this.authService.doForgotPassword(data.email);
        }
      },
      {
        text: 'Cancel',
        role: 'cancel',
        handler: () => {
          console.log('Cancel clicked');
        }
      }]
    });
    await alert.present();
  }



}
