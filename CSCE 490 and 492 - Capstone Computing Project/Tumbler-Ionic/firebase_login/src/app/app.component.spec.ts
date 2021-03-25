import { CUSTOM_ELEMENTS_SCHEMA } from '@angular/core';
import { TestBed, async } from '@angular/core/testing';

import { Platform } from '@ionic/angular';
import { SplashScreen } from '@ionic-native/splash-screen/ngx';
import { StatusBar } from '@ionic-native/status-bar/ngx';

import { AppComponent } from './app.component';
import { RouterTestingModule } from '@angular/router/testing';

/*
The code below is one unit test for the entire app component page. It
uses various providers and imports. A test begins in the it() function,
where the first parameter is a simple describer of the test and the
second paramter is a function call, in these cases () and async().
The constants are declared using a TestBed that is configured by a
separate module. The expect function passes in the constant or variable,
followed by a subroutine toBe() which can be used to ensure that what you
are passing in is what you expected it to be.
*/

describe('AppComponent', () => {

  let statusBarSpy, splashScreenSpy, platformReadySpy, platformSpy;

  beforeEach(async(() => {
    statusBarSpy = jasmine.createSpyObj('StatusBar', ['styleDefault']);
    splashScreenSpy = jasmine.createSpyObj('SplashScreen', ['hide']);
    platformReadySpy = Promise.resolve();
    platformSpy = jasmine.createSpyObj('Platform', { ready: platformReadySpy });

    TestBed.configureTestingModule({
      declarations: [AppComponent],
      schemas: [CUSTOM_ELEMENTS_SCHEMA],
      providers: [
        { provide: StatusBar, useValue: statusBarSpy },
        { provide: SplashScreen, useValue: splashScreenSpy },
        { provide: Platform, useValue: platformSpy },
      ],
      imports: [RouterTestingModule]
    }).compileComponents();
  }));

  it('should create the app', () => {
    const fixture = TestBed.createComponent(AppComponent);
    const app = fixture.debugElement.componentInstance;
    expect(app).toBeTruthy();
  });

  it('should initialize the app', async () => {
    TestBed.createComponent(AppComponent);
    expect(platformSpy.ready).toHaveBeenCalled();
    await platformReadySpy;
    expect(statusBarSpy.styleDefault).toHaveBeenCalled();
    expect(splashScreenSpy.hide).toHaveBeenCalled();
  });

});

//Unit tests begin here
describe('A simple truth tester', ()=>{
  var a = true;
  var b = false;
  it('It should be true', ()=>{
    expect(a).toBe(true);
  });
  it('Should not be the same', ()=>{
    expect(b).not.toBe(a);
  });
});

describe('Testing for null', ()=>{
  var c=34;
  var d=null;

  it('should be null', ()=>{
    expect(d).toBeNull();
  });
  it('should not be null', ()=>{
    expect(c).not.toBeNull();
  });
});

describe('toContain should work', ()=>{
  var email="test@email.com";
  it('should match', ()=>{
    expect(email).toContain("test");
  });
  it('should not match', ()=>{
    expect(email).not.toContain("operator");
  });
});

describe('should be equal', ()=>{
  var num=99;
  it('should match', ()=>{
    expect(num).toBeLessThanOrEqual(103);
  });
  it('should not match', ()=>{
    expect(num).toBeGreaterThanOrEqual(20);
  });
});