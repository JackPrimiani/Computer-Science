//Author: Mark McMurtury

import { Component, OnInit } from '@angular/core';
import { Router,ActivatedRoute } from '@angular/router';

import { EntryService } from '../entry.service';


@Component({
  selector: 'app-view-entry',
  templateUrl: './view-entry.page.html',
  styleUrls: ['./view-entry.page.scss'],
})
export class ViewEntryPage implements OnInit {
	current_fall:any = null;
	
	servertyScale:Array<any> = [
		"assets/Grade1.PNG",
		"assets/Grade2.PNG",
		"assets/Grade3.PNG",
		"assets/Grade4.PNG"
	];
	
  constructor(
    private router:Router,
    private route: ActivatedRoute,
	private entryService: EntryService
	) { }

  ngOnInit() {
    //console.log("onInit")
    this.route.params.subscribe(
      param => {
        this.current_fall = this.route.snapshot.params;
		date:this.current_fall.date;
		time:this.current_fall.time;
		timep:this.current_fall.category;
		injury:this.current_fall.photoURL;
		requriedMed:this.current_fall.requriedMed;
        serverty:this.current_fall.serverty;
		description:this.current_fall.description;
      }
    )
  }

  
  


}
