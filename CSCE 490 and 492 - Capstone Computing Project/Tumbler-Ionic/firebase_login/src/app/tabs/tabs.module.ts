import { IonicModule } from '@ionic/angular';
import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { TabsPageRoutingModule } from './tabs-routing.module';

import { TabsPage } from './tabs.page';
import { Routes } from '@angular/router';

import { AngularFireAuthModule } from '@angular/fire/auth';

const routes: Routes = [
  {
    path: 'tabs',
    component: TabsPage,
    children:[
        { path: 'tab1', loadChildren: '../tab1/tab1.module#Tab1PageModule' },
        { path: 'tab2', loadChildren: '../tab2/tab2.module#Tab2PageModule' },
        { path: 'qrcode', loadChildren: '../qrcode/qrcode.module#QrcodePageModule' 
      },

    ]
  },
  {
    path:'',
    redirectTo:'/tabs/tab1',
    pathMatch:'full'
  }
];

@NgModule({
  imports: [
    IonicModule,
    CommonModule,
    FormsModule,
    TabsPageRoutingModule,
    //AngularFireAuthModule
  ],
  declarations: [TabsPage]
})
export class TabsPageModule {}
