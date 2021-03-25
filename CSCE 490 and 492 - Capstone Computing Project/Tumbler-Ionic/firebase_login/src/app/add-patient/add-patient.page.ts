import { Component, OnInit } from '@angular/core';

import * as firebase from 'firebase';
import { Router,Routes, RouterModule } from '@angular/router';
import { QRScanner, QRScannerStatus } from '@ionic-native/qr-scanner/ngx';
import { Platform } from '@ionic/angular';


@Component({
  selector: 'app-add-patient',
  templateUrl: './add-patient.page.html',
  styleUrls: ['./add-patient.page.scss'],
  providers: [QRScanner],
})
export class AddPatientPage implements OnInit {

  encodedData = '';
  QRSCANNED_DATA: string;
  isOn = false;
  scannedData: {};
  scanSub: any;
  maxTime: any=5
  

  addParticipants(UID,Name){
    firebase.firestore().collection("permissions").doc(firebase.auth().currentUser.uid).collection("permissions").add({
      "UID":UID,
      "Name":Name
    })
	this.router.navigate(["/view-patients"]);
  }

  

  constructor(public platform: Platform,private router: Router,private qrScanner: QRScanner) {
    this.platform.backButton.subscribeWithPriority(0, () => {
      document.getElementsByTagName('body')[0].style.opacity = '2';
      this.closeScanner();
      this.scanSub.unsubscribe();
      
    });
   }

  ngOnInit() {
  }
  scan(){
  this.qrScanner.prepare()
  .then((status: QRScannerStatus) => {
     if (status.authorized) {
      this.isOn = true;
      this.qrScanner.show();
      this.scanSub = document.getElementsByTagName('body')[0].style.opacity = '0';
          debugger
       // camera permission was granted
      console.log('Made it to funtion');
       // start scanning
       this.scanSub = this.qrScanner.scan().subscribe((text: string) => {
         console.log('Scanned something', text);
         this.isOn = false;
         document.getElementsByTagName('body')[0].style.opacity = '1';
         this.QRSCANNED_DATA = text;
         if (this.QRSCANNED_DATA !== '') {
           this.closeScanner();
           this.scanSub.unsubscribe();

         }

       });
       

     } else if (status.denied) {
       // camera permission was permanently denied
       // you must use QRScanner.openSettings() method to guide the user to the settings page
       // then they can grant the permission from there
     } else {
       // permission was denied, but not permanently. You can ask for permission again at a later time.
     }
  }
  )
  .catch((e: any) => console.log('Error is', e));
  return this.QRSCANNED_DATA;
  
  }


  closeScanner() {
    this.isOn = false;
    this.qrScanner.hide();
    this.qrScanner.destroy();
  }
}
