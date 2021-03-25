//Author: Mark McMurtury

import { Component,OnInit } from '@angular/core';
import { Router } from '@angular/router';
//import { ActionSheetController } from '@ionic/angular';
import { EntryService } from '../entry.service';

@Component({
  selector: 'app-tab2',
  templateUrl: 'tab2.page.html',
  styleUrls: ['tab2.page.scss']
})
export class Tab2Page {
	falls = [];
	minDate;
	maxDate;
	filter = false;
	filtering = false;
	latest_date;
	
	servertyScale:Array<any> = [
		"assets/Grade1.PNG",
		"assets/Grade2.PNG",
		"assets/Grade3.PNG",
		"assets/Grade4.PNG"
	];
	
  constructor(
	private router: Router,
	public entryService: EntryService,
	 ) {}
	//private actionSheetCtrl: ActionSheetController
	ngOnInit(){
    console.log("00000000000000000000000000000000000000000000000000000000000")
    this.falls = this.entryService.getFalls();
	let today = new Date();
	//Latest day to experince a fall is today.
	this.latest_date = today.toISOString().slice(0, 10);
	this.maxDate = this.latest_date;
	this.minDate = this.latest_date;
    console.log(this.falls.length);
  }
	
	theFilter(){
		this.filter = true;
	}
	
	clearFilter(){
		this.filter = false;
		this.filtering = false;
	}
	appFilter(){
		this.filter = false;
		this.filtering = true;
		this.sortData();
	}
	
	sortData(){
		var feyear = this.minDate.slice(0, 4)*1;
		var femonth = this.minDate.slice(5, 7)*1;
		var feday = this.minDate.slice(8,10)*1;
		
		var fsyear = this.maxDate.slice(0, 4)*1;
		var fsmonth = this.maxDate.slice(5, 7)*1;
		var fsday = this.maxDate.slice(8,10)*1;
		
		console.log(fsyear);
		console.log(fsmonth);
		console.log(fsday);
		
		this.falls = [];
		var falling = this.entryService.falls;
		for(var i = 0; i < falling.length; i++){
			var year = falling[i].date.slice(0, 4)*1;
			var month = falling[i].date.slice(5, 7)*1;
			var day = falling[i].date.slice(8,10);
			
			if (year >= feyear && year <= fsyear){
				if (year == feyear && year == fsyear){
					if (month >= femonth && month <= fsmonth){
							if(femonth == fsmonth){
								if (day >= feday && day <= fsday){
									this.falls.push({
												  'date':falling[i].date,
												  'time':falling[i].time,
												  'timep':falling[i].timep,
												  'injury':falling[i].injury,
												  'requriedMed':falling[i].requriedMed,
												  'serverty':falling[i].serverty,
												  'description':falling[i].description
											  });
								}
							} else {
								if ( month == femonth){
									if (day >= feday){
										this.falls.push({
												  'date':falling[i].date,
												  'time':falling[i].time,
												  'timep':falling[i].timep,
												  'injury':falling[i].injury,
												  'requriedMed':falling[i].requriedMed,
												  'serverty':falling[i].serverty,
												  'description':falling[i].description
											  });
									}
								} else if (month <= fsmonth){
									if (day <= fsday){
										this.falls.push({
												  'date':falling[i].date,
												  'time':falling[i].time,
												  'timep':falling[i].timep,
												  'injury':falling[i].injury,
												  'requriedMed':falling[i].requriedMed,
												  'serverty':falling[i].serverty,
												  'description':falling[i].description
											  });
									}
								} else {
									this.falls.push({
												  'date':falling[i].date,
												  'time':falling[i].time,
												  'timep':falling[i].timep,
												  'injury':falling[i].injury,
												  'requriedMed':falling[i].requriedMed,
												  'serverty':falling[i].serverty,
												  'description':falling[i].description
											  });
								}
							}
						}
				} else if (year == feyear){
					if (month == femonth){
						if (day >= feday){
							this.falls.push({
										  'date':falling[i].date,
										  'time':falling[i].time,
										  'timep':falling[i].timep,
										  'injury':falling[i].injury,
										  'requriedMed':falling[i].requriedMed,
										  'serverty':falling[i].serverty,
										  'description':falling[i].description
									  });
						}
					} else if (month > femonth){
						this.falls.push({
							  'date':falling[i].date,
							  'time':falling[i].time,
							  'timep':falling[i].timep,
							  'injury':falling[i].injury,
							  'requriedMed':falling[i].requriedMed,
							  'serverty':falling[i].serverty,
							  'description':falling[i].description
						  });
					}
				} else if (year == fsyear){
					if (month == fsmonth){
						if (day <= fsday){
							this.falls.push({
										  'date':falling[i].date,
										  'time':falling[i].time,
										  'timep':falling[i].timep,
										  'injury':falling[i].injury,
										  'requriedMed':falling[i].requriedMed,
										  'serverty':falling[i].serverty,
										  'description':falling[i].description
									  });
						}
					} else if (month < fsmonth){
						this.falls.push({
							  'date':falling[i].date,
							  'time':falling[i].time,
							  'timep':falling[i].timep,
							  'injury':falling[i].injury,
							  'requriedMed':falling[i].requriedMed,
							  'serverty':falling[i].serverty,
							  'description':falling[i].description
						  });
					}
				} else {
					this.falls.push({
							  'date':falling[i].date,
							  'time':falling[i].time,
							  'timep':falling[i].timep,
							  'injury':falling[i].injury,
							  'requriedMed':falling[i].requriedMed,
							  'serverty':falling[i].serverty,
							  'description':falling[i].description
						  });
				}
			}
		}
	}
	/* async presentActionSheet(){
		const actionSheet = await this.actionSheetCtrl.create({
			header: 'Filter by date',
			
			<ion-icon size="large" name="alert-circle-outline" 
						*ngIf = "fall.injury" color="danger"></ion-icon>
			
		})
	} */
}
