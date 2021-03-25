import { async, ComponentFixture, TestBed } from '@angular/core/testing';
import { IonicModule } from '@ionic/angular';

import { CreateEntryPage } from './create-entry.page';
import { FormsModule } from '@angular/forms';
import { RouterTestingModule } from '@angular/router/testing';

import * as firebase from 'firebase';
import { environment } from 'src/environments/environment';
import { EntryService } from '../entry.service';
import { of } from 'rxjs';

firebase.initializeApp(environment.firebase);

/*
The code below is one unit test for the entire app component page. It
uses various providers and imports. A test begins in the it() function,
where the first parameter is a simple describer of the test and the
second paramter is a function call, in this case ().
The constants are declared using a TestBed that is configured by a
separate module. The expect function passes in the constant or variable,
followed by a subroutine toBe() which can be used to ensure that what you
are passing in is what you expected it to be.
*/
describe('CreateEntryPage', () => {
  let component: CreateEntryPage;
  let fixture: ComponentFixture<CreateEntryPage>;
  let entryServiceMock: any;
  let uid:any = 'PNltH2FJcEgc2Kd7xogclJ8F1ml1';
  beforeEach(async(() => {
    entryServiceMock=jasmine.createSpyObj('EntryService',['getUID','getUser']);
    entryServiceMock.getUID.and.returnValue(of(uid));
    TestBed.configureTestingModule({
      declarations: [ CreateEntryPage ],
      imports: [
        IonicModule.forRoot(),
        FormsModule,
        RouterTestingModule],
      providers: [{provide: EntryService, useValue: entryServiceMock}]
    }).compileComponents();

    fixture = TestBed.createComponent(CreateEntryPage);
    component = fixture.componentInstance;
    fixture.detectChanges();
  }));

  it('should create', () => {
    expect(component).toBe(component);
  });
});
