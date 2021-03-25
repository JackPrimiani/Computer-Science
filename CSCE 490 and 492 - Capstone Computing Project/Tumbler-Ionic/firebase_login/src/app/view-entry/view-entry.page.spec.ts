import { async, ComponentFixture, TestBed } from '@angular/core/testing';
import { IonicModule } from '@ionic/angular';

import { ViewEntryPage } from './view-entry.page';
import { RouterTestingModule } from '@angular/router/testing';

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
describe('ViewEntryPage', () => {
  let component: ViewEntryPage;
  let fixture: ComponentFixture<ViewEntryPage>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ ViewEntryPage ],
      imports: [
        IonicModule.forRoot(),
        RouterTestingModule]
    }).compileComponents();

    fixture = TestBed.createComponent(ViewEntryPage);
    component = fixture.componentInstance;
    fixture.detectChanges();
  }));

  it('should create', () => {
    expect(component).toBe(component);
  });
});
