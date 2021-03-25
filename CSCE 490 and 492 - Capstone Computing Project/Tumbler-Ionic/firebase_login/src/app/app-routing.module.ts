import { NgModule } from '@angular/core';
import { PreloadAllModules, RouterModule, Routes } from '@angular/router';

const routes: Routes = [
  
  {
    path: '',
    loadChildren: () => import('./login/login.module').then( m => m.LoginPageModule)
  },
  {
    path: 'tab1',
    loadChildren: () => import('./tab1/tab1.module').then( m => m.Tab1PageModule)
  },
  {
    path: 'signin',
    loadChildren: () => import('./signin/signin.module').then( m => m.SigninPageModule)
  },
  {
    path: 'login',
    loadChildren: () => import('./login/login.module').then( m => m.LoginPageModule)
  },
  {
    path: 'create-entry',
    loadChildren: () => import('./create-entry/create-entry.module').then( m => m.CreateEntryPageModule)
  },
  {
    path: 'view-entry',
    loadChildren: () => import('./view-entry/view-entry.module').then( m => m.ViewEntryPageModule)
  },
 { path: '', loadChildren: './tabs/tabs.module#TabsPageModule' },
  {
    path: 'add-patient',
    loadChildren: () => import('./add-patient/add-patient.module').then( m => m.AddPatientPageModule)
  },
  {
    path: 'create-entry',
    loadChildren: () => import('./create-entry/create-entry.module').then( m => m.CreateEntryPageModule)
  },
  {
    path: 'view-entry',
    loadChildren: () => import('./view-entry/view-entry.module').then( m => m.ViewEntryPageModule)
  },
 { path: '', loadChildren: './tabs/tabs.module#TabsPageModule' },
  {
    path: 'add-patient',
    loadChildren: () => import('./add-patient/add-patient.module').then( m => m.AddPatientPageModule)
  },
  {
    path: 'view-patients',
    loadChildren: () => import('./view-patients/view-patients.module').then( m => m.ViewPatientsPageModule)
  },  {
    path: 'doctortabs',
    loadChildren: () => import('./doctortabs/doctortabs.module').then( m => m.DoctortabsPageModule)
  },
  {
    path: 'qrcode',
    loadChildren: () => import('./qrcode/qrcode.module').then( m => m.QrcodePageModule)
  },

];
@NgModule({
  imports: [
    RouterModule.forRoot(routes, { preloadingStrategy: PreloadAllModules })
  ],
  exports: [RouterModule]
})
export class AppRoutingModule {}
