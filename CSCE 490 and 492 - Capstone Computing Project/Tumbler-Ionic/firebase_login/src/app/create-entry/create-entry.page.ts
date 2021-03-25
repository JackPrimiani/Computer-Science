//Author: Mark McMurtury

import { Component,OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { EntryService } from '../entry.service';
import { AlertController } from '@ionic/angular';

@Component({
  selector: 'app-create-entry',
  templateUrl: './create-entry.page.html',
  styleUrls: ['./create-entry.page.scss'],
})

export class CreateEntryPage implements OnInit {
	user:any = null;
	stage:number = 0;
	review:boolean = false;
	other:boolean = false;
	message:string = "Next";
	
	
	date:string = null;
	time:number = null;
	timep:string = null;
	injury:boolean = null;
	requriedMedical:boolean = false;
	location:string = null;
	serverty:number = null;
	description:string = "";
	earliest_date:string;
	latest_date:string;
	
	questions:Array<string> = [
		"When did you experience the fall?",
		"Did you experience an injury,and if so did it require medical attention?",
		"Please rate your fall according to these options.",
		"Describe your fall."
	];
	
	servertyScale:Array<any> = [
		{"pic":"assets/Grade1.PNG", "selected":false},
		{"pic":"assets/Grade2.PNG", "selected":false},
		{"pic":"assets/Grade3.PNG", "selected":false},
		{"pic":"assets/Grade4.PNG", "selected":false}
	];
	
	describFall:Array<any> = [
		{"des":"While traveling to the bathroom.", "selected":false},
		{"des":"During toileting.", "selected":false},
		{"des":"Due to feeling lightheded when standing.", "selected":false},
		{"des":"Due to feeling dizzy, such as the room is spinning.", "selected":false},
		{"des":"Tripped over an object.", "selected":false},
		{"des":"Due to a poorly lit environment.", "selected":false},
		{"des":"Other", "selected":false}
	];
	
  
  constructor(
	private router: Router,
	public entryService: EntryService,
	private alertCtrl: AlertController) { }

  ngOnInit(){
    this.user = this.entryService.getUser();
	let today = new Date();
	//Latest day to experince a fall is today.
	this.latest_date = today.toISOString().slice(0, 10);
	//Earliest day to experince a fall is one years ago.
	let earliest_date = new Date(today.getTime() - 1000*24*365*1);
	this.earliest_date = earliest_date.toISOString().slice(0, 10);
	//let stage = 0;
    console.log("Getting user.");
	}
	
	cancel(){
		console.log("Cancel Entry");
		this.stage = 0;
		this.router.navigate(["/tabs/tab1"]);
	}
	next(){
		this.stage = this.stage +1;
		if(this.stage == 3){
			this.message = "Add/Create";
		}	
		if(this.stage == 4){
				//Push the entry.
				this.entryService.addEntry(
					this.date.slice(0, 10),
					this.time,
					this.timep,
					this.injury,
					this.requriedMedical,
					this.servertyencode(),
					this.descriptionencode()
				);
				this.router.navigate(["/tabs/tab1"]);
		}		
	}
	check(){
		switch (this.stage) {
			case 0:
				if ( this.date == null ){
					this.warning("Please select the date.");
				} else if (this.time == null){
					this.warning("Please select the time.");
				} else if ( this.timep == null){
					this.warning("Please select whether it was A.M. or P.M.");
				} else {
					this.next();
				}
				break;
			case 1:
				if (this.injury == null){
					this.warning("Plese indicate if you experience an injury.");
				} else{
					this.next();
				}
				break;
			case 2:
				if (this.servertyencode() == null){
					this.warning("Please select the severity.");
				} else {
					this.next();
				}
				break;
			case 3:
				if ( this.descriptionencode() == null){
					this.warning("Please Describe the fall.");
				} else{
					this.next();
				}
				break;
			case 4:
				break;
			default:
				console.log("Never reach");
				break;
		}
	}
	async warning(err){
		const alert = await this.alertCtrl.create({
		  header: 'Invalid',
		  message: err,
		  buttons: [
			{ text: 'Okay' }
		  ]
	  });
	  await alert.present();
	}
	servertyencode(){
		for(var i = 0; i < this.servertyScale.length; i++){
			if(this.servertyScale[i].selected){
				return i;
			} else if (i == this.servertyScale.length -1){
				return null;
			}
		}
	}
	descriptionencode(){
		if(this.other){
			return this.description;
		}
		for(var i = 0; i < this.describFall.length; i++){
			if(this.describFall[i].selected){
				return this.describFall[i].des;
			} else if (i == this.describFall.length -1){
				return null;
			}
		}
	}
	checkOther(){
		if(this.describFall[6].selected){
			this.other = true;
		} else {
			this.other = false;
			this.description = "";
		}
	}
	resetSel(){
		for(var i = 0; i < this.servertyScale.length; i++){
			if(this.servertyScale[i].selected){
				this.servertyScale[i].selected = false;
			}
		}
	}
	resetSelDes(){
		for(var i = 0; i < this.describFall.length; i++){
			if(this.describFall[i].selected){
				this.describFall[i].selected = false;
			}
		}
	}
	
}
