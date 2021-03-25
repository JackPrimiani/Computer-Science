import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { ViewPatientsPageRoutingModule } from './view-patients-routing.module';

import { ViewPatientsPage } from './view-patients.page';
import { Route } from '@angular/router';
import { Routes } from '@angular/router';

const routes: Routes = [
  {
  path: 'view-patients',
  component:ViewPatientsPage,
  children: [
    { path: 'tab2', loadChildren: '../tab2/tab2.module#Tab2PageModule' },
  ]
}
];

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    ViewPatientsPageRoutingModule
  ],
  declarations: [ViewPatientsPage]
})
export class ViewPatientsPageModule {}
