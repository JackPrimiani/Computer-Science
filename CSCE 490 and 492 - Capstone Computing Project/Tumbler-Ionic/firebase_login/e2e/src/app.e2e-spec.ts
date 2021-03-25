import { AppPage } from './app.po';
import { browser, element, by } from 'protractor';


describe('Doctor Login', () => {
  let page: AppPage;
  const app = new AppPage();
  beforeEach(() => {
    browser.get('');
    element(by.css(".title")).getText();
    browser.driver.sleep(500);
  });

  it('should display welcome message', () => {
    let lessonToTest = element.all(by.css('.title')).getText;

    // Trigger a click to navigate to module
    // Wait
    browser.driver.sleep(500);

    // Check if there is content
    expect(element(by.css('.title')).getText()).toEqual("Login");

  });
  it('should be able to login', () =>{
    element(by.css('.emailInput')).click();
    browser.sleep(2000);
    var input = 'vincentj16@yahoo.com';
    browser.actions().sendKeys(input).perform();
    browser.sleep(500);
    const pl = element(by.css('.passInput')).click();
    input = 'password';
    browser.sleep(500);
    browser.actions().sendKeys(input).perform();
    element(by.css('.loginButton')).click();
    browser.sleep(4000);
  })
});

describe('Patient Login', () => {
  let page: AppPage;
  const app = new AppPage();
  beforeEach(() => {
    browser.restartSync();
    browser.get('/');
    element(by.css(".title")).getText();
    browser.driver.sleep(500);
  });
  it('should be able to login', () =>{
    element(by.css('.emailInput')).click();
    browser.sleep(2000);
    var input = 'jmnj72@yahoo.com';
    browser.actions().sendKeys(input).perform();
    browser.sleep(500);
    const pl = element(by.css('.passInput')).click();
    input = 'password';
    browser.sleep(500);
    browser.actions().sendKeys(input).perform();
    element(by.css('.loginButton')).click();
    browser.sleep(4000);
  })

  it('get the right patient ID', () =>{
    element(by.css('.emailInput')).click();
    browser.sleep(2000);
    var input = 'jmnj72@yahoo.com';
    browser.actions().sendKeys(input).perform();
    browser.sleep(500);
    const pl = element(by.css('.passInput')).click();
    input = 'password';
    browser.sleep(500);
    browser.actions().sendKeys(input).perform();
    element(by.css('.loginButton')).click();
    browser.sleep(1000);
    expect(element(by.name('uid')).getWebElement().getText()).toEqual("HqlbbTGE3gMN3AzHKa7mJ4tCPX42");
  })
});

describe('Sign up', () => {
  let page: AppPage;
  const app = new AppPage();
  beforeEach(() => {
    browser.restartSync();
    browser.get('/');
    element(by.css(".title")).getText();
    browser.driver.sleep(500);
  });
  it('navigate to sign in', () =>{
    element(by.css('.signUpButton')).click()
    browser.sleep(1000);
  })

  it('do signup', () =>{
    //TODO
  })
});

