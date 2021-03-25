import { Component, OnInit } from '@angular/core';
import * as firebase from 'firebase';
import { Router,Routes, RouterModule } from '@angular/router';
import { EntryService } from '../entry.service';
import { AlertController } from '@ionic/angular';

@Component({
  selector: 'app-view-patients',
  templateUrl: './view-patients.page.html',
  styleUrls: ['./view-patients.page.scss'],
})
export class ViewPatientsPage implements OnInit {

	patients:Array<any> = [];
	
  constructor(private router: Router,public entryService: EntryService,private alertCtrl: AlertController) { }

  ngOnInit() {
	  this.clearpatientArr();
	  this.getParticipants(this.patients);
	 
  }

  pUID ="";

  getParticipants(patients){
	console.log(this.entryService.getUID());
	return new Promise((resolve, reject) => {
	  firebase.firestore().collection("permissions").doc(this.entryService.getUID()).collection("permissions")
		.get()
		.then((querySnapshot) => {
		  let arr = [];
		  querySnapshot.forEach(function(doc) {
			var obj = JSON.parse(JSON.stringify(doc.data()));
			obj.id = doc.id;
			//obj.eventId = doc.id;
			arr.push(obj);
			patients.push(obj);
			console.log(patients.length)
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
  getFall(UID){
		console.log(UID);
		this.pUID = UID;
		this.entryService.falls = [];
		this.entryService.getThings(this.pUID, this.entryService.falls);
	  this.router.navigate(['/doctortabs/tab2']);
  }
  addPatient(){
	  this.router.navigate(["/add-patient"]);
  }

  clearpatientArr(){ 

	  this.patients = [];
  }

  async presentConfirm(ID,patient) {
	let alert = await this.alertCtrl.create({
		message: 'Are you sure you want to delete this patient?',
		buttons: [
			{
				text: 'Cancel',
				role: 'cancel',
				handler: () => {
					console.log('Cancel clicked');
				}
			},
			{
				text: 'Delete User',
				handler: () => {
					this.deletePatient(ID);
					this.removePatient(patient);
					console.log('Delete clicked');
				}
			}
		]
	});
	await alert.present();
  }


  deletePatient(ID)
  {
	  console.log(ID);
	  firebase.firestore().collection("permissions").doc(firebase.auth().currentUser.uid).collection("permissions").doc(ID).delete().then(function() {
		console.log("Document successfully deleted!");
	}).catch(function(error) {
		console.error("Error removing document: ", error);
	});
  }

  removePatient(patient){
    let index = this.patients.indexOf(patient);
    if(index > -1){
      this.patients.splice(index, 1);
    }
}
  
}
