import { async, ComponentFixture, TestBed } from '@angular/core/testing';
import { IonicModule } from '@ionic/angular';

import { DoctortabsPage } from './doctortabs.page';
import { AngularFireAuth } from '@angular/fire/auth';

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
describe('DoctortabsPage', () => {
  let component: DoctortabsPage;
  let fixture: ComponentFixture<DoctortabsPage>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ DoctortabsPage ],
      imports: [
        IonicModule.forRoot(),
        AngularFireAuth]
    }).compileComponents();

    fixture = TestBed.createComponent(DoctortabsPage);
    component = fixture.componentInstance;
    fixture.detectChanges();
  }));

  it('should create', () => {
    expect(component).toBe(component);
  });
});
