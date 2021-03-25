import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { ViewPatientsPage } from './view-patients.page';

const routes: Routes = [
  {
    path: '',
    component: ViewPatientsPage,
    children: [
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
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class ViewPatientsPageRoutingModule {}
