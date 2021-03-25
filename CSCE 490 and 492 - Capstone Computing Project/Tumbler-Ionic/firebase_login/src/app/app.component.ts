import { Component } from '@angular/core';
import { Router } from '@angular/router';
import { Platform } from '@ionic/angular';
import { SplashScreen } from '@ionic-native/splash-screen/ngx';
import { StatusBar } from '@ionic-native/status-bar/ngx';

import * as firebase from 'firebase';
import { EntryService } from './entry.service';
import { ViewEntryPage } from './view-entry/view-entry.page';
import { FirebaseApp } from '@angular/fire';
// firebase config settings
/*var firebaseConfig = {
  apiKey: "AIzaSyAR_cPJ-G_4wK7y-vJ_Qb8s0Mq82G9_kAI",
  authDomain: "fir-login-a4a58.firebaseapp.com",
  databaseURL: "https://fir-login-a4a58.firebaseio.com",
  projectId: "fir-login-a4a58",
  storageBucket: "fir-login-a4a58.appspot.com",
  messagingSenderId: "995951007156",
  appId: "1:995951007156:web:2b5bccfc2ba416467ecee1",
  measurementId: "G-QX7P56RJQD"
};*/
@Component({
  selector: 'app-root',
  templateUrl: 'app.component.html',
  styleUrls: ['app.component.scss']
})
export class AppComponent {
  rootPage: any = ViewEntryPage;

  constructor(
    private router : Router,
    private platform: Platform,
    private splashScreen: SplashScreen,
    private statusBar: StatusBar
  ) {
    this.initializeApp();
  }
  
  initializeApp() {
    
    this.platform.ready().then(() => {
      this.router.navigate(["/login"]);
      this.statusBar.styleDefault();
      this.splashScreen.hide();
    });
    /*firebase.initializeApp(firebaseConfig);
    var db = firebase.firestore();*/
  }
}
