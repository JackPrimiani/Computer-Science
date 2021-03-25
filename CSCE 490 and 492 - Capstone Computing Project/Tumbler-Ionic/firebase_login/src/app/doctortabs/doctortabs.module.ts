import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { DoctortabsPageRoutingModule } from './doctortabs-routing.module';
import { Routes } from '@angular/router';
import { DoctortabsPage } from './doctortabs.page';

const routes: Routes = [
  {
    path: 'doctorstabs',
    component: DoctortabsPage,
    children:[
        { path: 'add-patient', loadChildren: '../add-patient/add-patient.module#AddPatientPageModule' },

    ]
  },
  {
    path:'',
    redirectTo:'/doctortabs/view-patients',
    pathMatch:'full'
  }
];

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    DoctortabsPageRoutingModule
  ],
  declarations: [DoctortabsPage]
})
export class DoctortabsPageModule {}
