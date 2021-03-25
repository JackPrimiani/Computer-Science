import { Component, OnInit } from '@angular/core';
import { Router,ActivatedRoute } from '@angular/router';
import { AuthService } from '../services/auth.service';
import { AngularFireAuth, AngularFireAuthModule } from '@angular/fire/auth';
import { AngularFireModule } from '@angular/fire';
import * as firebase from 'firebase';
import { EntryService } from '../entry.service';
import { AlertController } from '@ionic/angular';

@Component({
  selector: 'app-signin',
  templateUrl: './signin.page.html',
  styleUrls: ['./signin.page.scss'],
  providers: [AuthService, AngularFireAuth, AngularFireModule],
})
export class SigninPage implements OnInit {
	errorMessage: string = '';
  constructor(angularFireAuth: AngularFireAuth, 
				private authService: AuthService,
				private router:Router,
				private alertCtrl: AlertController) { }

  ngOnInit() {
  }


isDoctor(isDoctor){
  if(isDoctor){
    console.log("success");
    console.log(isDoctor);
    return isDoctor;
  }
  else{
    isDoctor = false;
    console.log("fail");
    console.log(isDoctor);
    return isDoctor;
  }
  return isDoctor;
}

tryRegister(email,password,Doctor,Cpassword){
  if (password != Cpassword)
  {
    this.warning("Passwords do not match");
    return;
  }
  this.authService.doRegister(email,password)
  .then(res=> {
    this.authService.doLogin(email, password)
    .then(res => {
      firebase.firestore().collection("roles").doc(firebase.auth().currentUser.uid).set({'doctor':this.isDoctor(Doctor)});

      firebase.firestore().collection("users").doc(firebase.auth().currentUser.uid).collection("Info").doc(firebase.auth().currentUser.uid).set({
        'email':email
      });
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
     
    }, err => {
      this.errorMessage = err.message;
      console.log(err)
	  this.warning(err);
    })

  }, err =>{
    this.errorMessage = err.errorMessage;
    console.log(err)
	this.warning(err);;
  })
}
	
	async warning( error ){
	  const alert = await this.alertCtrl.create({
		  header: 'Error',
		  message: error,
		  buttons: [
			{ text: 'Okay' }
		  ]
	  });
	  await alert.present();
  }

}
