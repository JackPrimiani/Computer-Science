//Mark McMurtury
//Vincent Josephs
//Jack Primiani
//Cody Butler

/*
Main Page is now on home_page
*/

import 'package:flutter/material.dart';
import 'package:learning_flutter/services/authentication.dart';
import 'package:learning_flutter/pages/root_page.dart';

void main() => runApp(new MyApp());

class MyApp extends StatelessWidget {

  @override
  Widget build(BuildContext context) {
    return new MaterialApp(
        title: 'Flutter Login Demo',
        debugShowCheckedModeBanner: false,
        theme: new ThemeData(
          // This is the theme of your application.
          //Below sets the background and header colors.
            brightness: Brightness.dark,
            primaryColor: Colors.red,
            //primarySwatch: Colors.red,
            accentColor: Colors.amberAccent
          //backgroundColor: Colors.blueAccent,
          //This changes the text color.
          /*textTheme: TextTheme(
          body1: TextStyle(),
          body2: TextStyle(),
        ).apply(
          bodyColor: Colors.amberAccent,
          displayColor: Colors.black
        )*/
        ),
        home: new RootPage(auth: new Auth()));
  }
}