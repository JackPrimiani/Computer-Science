import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { DoctortabsPage } from './doctortabs.page';

const routes: Routes = [
  {
    path: '',
    component: DoctortabsPage,
    children: [
      {
        path: 'add-patient',
        children: [
          {
            path: '',
            loadChildren: () =>
            import('../add-patient/add-patient.module').then(m => m.AddPatientPageModule)
          }
        ]
      },
      {
        path: 'view-patients',
        children: [
          {
            path: '',
            loadChildren: () =>
              import('../view-patients/view-patients.module').then(m => m.ViewPatientsPageModule)
          }
        ]
      },
      {
        path: 'tab2',
        children: [
          {
            path: '',
            loadChildren: () =>
              import('../tab2/tab2.module').then(m => m.Tab2PageModule)
          }
        ]
      },
      

    ]
  },{
    path: '',
    redirectTo: 'doctortabs/view-patients',
    pathMatch: 'full'
    }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class DoctortabsPageRoutingModule {}
