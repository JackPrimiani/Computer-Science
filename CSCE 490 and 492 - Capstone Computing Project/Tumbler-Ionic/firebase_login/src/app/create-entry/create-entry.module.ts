import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { CreateEntryPageRoutingModule } from './create-entry-routing.module';

import { CreateEntryPage } from './create-entry.page';
import { environment } from 'src/environments/environment';
import { AngularFireModule } from '@angular/fire';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    AngularFireModule.initializeApp(environment.firebase),
    CreateEntryPageRoutingModule
  ],
  declarations: [CreateEntryPage]
})
export class CreateEntryPageModule {}
