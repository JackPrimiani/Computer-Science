import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { RouteReuseStrategy } from '@angular/router';

import { IonicModule, IonicRouteStrategy } from '@ionic/angular';
import { SplashScreen } from '@ionic-native/splash-screen/ngx';
import { StatusBar } from '@ionic-native/status-bar/ngx';
import { environment } from '../environments/environment'
import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { AuthService } from './services/auth.service';
import { LoginPageModule } from './login/login.module';
import { AngularFireAuthModule } from '@angular/fire/auth';
import { AngularFireModule } from '@angular/fire';
import { AngularFirestoreModule } from '@angular/fire/firestore';
import * as firebase from 'firebase';
import { QRScanner } from '@ionic-native/qr-scanner/ngx';
import { QRCodeModule } from 'angularx-qrcode';

//import { environment } from 'src/environments/environment';

//firebase.initializeApp(environment.firebase);
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
@NgModule({
  declarations: [AppComponent],
  entryComponents: [],

  imports: [BrowserModule, 
    IonicModule.forRoot(), 
    AppRoutingModule, 
    AngularFireModule.initializeApp(environment.firebase),
    AngularFirestoreModule],

  providers: [
    StatusBar,
    SplashScreen,
    { provide: RouteReuseStrategy, 
      useClass: IonicRouteStrategy },
    QRScanner
  ],
  bootstrap: [AppComponent]
})
export class AppModule {}
