import { Component } from '@angular/core';
import { AuthService } from '../services/auth.service';
import { Router,Routes, RouterModule } from '@angular/router';
import { AngularFireAuth, AngularFireAuthModule } from '@angular/fire/auth';
import { AngularFireModule } from '@angular/fire';
import { EntryService } from '../entry.service';
@Component({
  selector: 'app-tabs',
  templateUrl: 'tabs.page.html',
  styleUrls: ['tabs.page.scss'],
  providers: [AuthService, AngularFireAuth, AngularFireModule],
})
export class TabsPage {

  errorMessage: string = '';
  constructor( 
    private authService: AuthService,
    private router: Router,
    public entryService: EntryService) {}

  logout(){
    console.log(this.entryService.getFallArr());
    console.log("0000000000000000000000000000000000000000000000000000000000000000000000000000000000000")
    this.entryService.clearList();
    console.log(this.entryService.getFallArr());
    console.log("made it to funtion");
    this.authService.doLogout()
    .then(res => {
      this.router.navigate(["/login"]);
     }, err => {
       this.errorMessage = err.message;
       console.log(err)
     })
  }

}
