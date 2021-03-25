import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { AddPatientPageRoutingModule } from './add-patient-routing.module';

import { AddPatientPage } from './add-patient.page';
import { ExploreContainerComponentModule } from '../explore-container/explore-container.module';
@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    AddPatientPageRoutingModule
  ],
  declarations: [AddPatientPage]
})
export class AddPatientPageModule {}
