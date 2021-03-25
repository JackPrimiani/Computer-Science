import { Component, OnInit } from '@angular/core';
import { QRCodeModule } from 'angularx-qrcode';
import * as firebase from 'firebase';
import { EntryService } from '../entry.service';
@Component({
  selector: 'app-qrcode',
  templateUrl: './qrcode.page.html',
  styleUrls: ['./qrcode.page.scss'],
})
export class QrcodePage implements OnInit {
  user:any = null;
  public patientQR: string = null;
  UserID = firebase.auth().currentUser.uid;
  constructor( public entryService: EntryService,) { this.patientQR = this.UserID;}

  ngOnInit() {
    this.user = this.entryService.getUser();
    console.log("Getting user.");
  }

}
