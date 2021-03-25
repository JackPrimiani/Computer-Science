## Authors

 Vincent Josephs vjosephs@email.sc.edu<br>
 Jack Primiani primiani@email.sc.edu<br>
 Mark McMurtury mcmurtum@email.sc.edu<br>
 Cody Butler cnbutler@email.sc.edu<br>
 Christopher Fulton cjfulton@email.sc.edu

## Tumbler
 This app was proposed by our client, Alicia Flasch. The app has been designed to quickly log patient entries and present them to their  care provider. The app was originally intended to be an iOS app, but due to some restrictions, has since been transformed into android app, that could also be ported to iOS at a later time. This README, will be updated as the app is worked on throughout the year. 
## Technologies
 For this app we will be using Ionic as our development platform. This means you will need:<br>
   1. Ionic:<br>
      
   This link https://ionicframework.com/docs/installation/cli will assist you with installing Ionic. Follow
   the instructions to complete the installation.<br>
      
2. Android Studio<br>
      
   This link https://developer.android.com/studio will assist you with installing Andriod Studio. 
   Follow the instructions to install the IDE. '<br>

3. Visual Studio Code<br>

   This link https://code.visualstudio.com/Download will allow you to download and install visual studio code. This is the another IDE you can choose, if you do not want to use Andriod Studio.<br>
      
4. An Andriod Emulator or Physcial Android Phone<br>
     
   Android Studio has a built-in emulator, however, if you can not get it to work, you can use the
   Genymotion plugin for Andriod Studio which can be at https://www.genymotion.com/plugins/ .  
   Alternatively you can plug your Android phone into your computer to run the app. This link 
   https://www.digitaltrends.com/mobile/how-to-get-developer-options-on-android/ will run you through 
   putting your specific phone model into developer mode. After that install the app and run.
          
## Running
   Using the command "ionic serve" will allow you to view the app in your browser, however to test the apk you will need an emulator.
   To run the apk simply start your emulator, then drag-and-drop the apk onto the running emulator. After that the apk should automatically install. From there just start the app. The option to test the app on a physical android device is possible if phone is first set to developer mode, instructions for this can be found above.
 
 ## Testing
   Go to your upper most directory for your code, the directory that contains the node_modules and src folders. Using the command "npm install karma --save-dev" to install Karma to your project package.json file in that directory. Then run "npm install karma-jasmine karma-chrome-launcher jasmine-core --save-dev" in that same directory. This will install the Jasmine plugins needed for unit testing the application. A good recommendation for the testing is to also run "npm install -g karma-cli" as this will install the karma client, which will allow karma to run locally. You will have to set up the client, so go with the recommended settings for basic tests or customize it for more personalization. Run "npm install" to ensure all packages are installed.
   
   To test the unit tests run "npm test" in the directory with the packages.json file. To write unit tests, go into the src folder and open the spec.ts file you want to write tests in your editor. Once you have written your tests, save the code and run "npm test." This will open a Jasmine web browser, which will display which tests failed or a screen displaying a message that all tests passed. If a test failed it will display an error message, and list the error that was prompted for each of the various spec.ts files.
   
  To run the behavioral tests, go into the terminal and use the command "npm run e2e". This should open another window in Chrome, which will then run through the tests. At the end of the tests, it will give you a read out in your terminal off all the tests that have passed and failed. To write behavioral tests go into the 'e2e' folder and open the file "app.e2e-spec.ts". from there you can begin to write your tests.
