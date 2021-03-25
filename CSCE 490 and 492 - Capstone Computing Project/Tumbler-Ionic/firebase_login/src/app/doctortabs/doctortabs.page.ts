import { Component, OnInit } from '@angular/core';
import { AuthService } from '../services/auth.service';
import { Router,Routes, RouterModule } from '@angular/router';
import { AngularFireAuth } from '@angular/fire/auth';
import { AngularFireModule } from '@angular/fire';
import { EntryService } from '../entry.service';

 //AngularFireAuthModule may need to be put into the providers and reimported
@Component({
  selector: 'app-doctortabs',
  templateUrl: './doctortabs.page.html',
  styleUrls: ['./doctortabs.page.scss'],
  providers: [AuthService, AngularFireAuth, AngularFireModule],
  
})
export class DoctortabsPage implements OnInit {
  errorMessage: string = '';
  constructor( private authService: AuthService,
    private router: Router,
    public entryService: EntryService,
    ) { }

  logout(){
    this.entryService.clearList();
    console.log("made it to funtion");
    this.authService.doLogout()
    .then(res => {
      this.router.navigate(["/login"]);
     }, err => {
       this.errorMessage = err.message;
       console.log(err)
     })
  }

  ngOnInit() {
  }

}
