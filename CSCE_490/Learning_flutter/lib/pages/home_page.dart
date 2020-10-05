//Mark McMurtury
//Vincent Josephs
//Jack Primiani
//Cody Butler

import 'package:flutter/material.dart';
import 'package:learning_flutter/services/authentication.dart';
import 'package:flutter/foundation.dart';
import 'dart:math';
import 'package:learning_flutter/Entry.dart';


class HomePage extends StatefulWidget {
  HomePage({Key key, this.auth, this.userId, this.logoutCallback})
      : super(key: key);

  final BaseAuth auth;
  final VoidCallback logoutCallback;
  final String userId;

  @override
  State<StatefulWidget> createState() => new _HomePageState();
}

class _HomePageState extends State<HomePage> {


  signOut() async {
    try {
      await widget.auth.signOut();
      widget.logoutCallback();
    } catch (e) {
      print(e);
    }
  }

  @override
  Widget build(BuildContext context) {
    return new Scaffold(
      appBar: new AppBar(
        title: new Text('Main Page'),
        actions: <Widget>[
          new FlatButton(
              child: new Text('Logout',
                  style: new TextStyle(fontSize: 17.0, color: Colors.white)),
              onPressed: signOut)
        ],
      ),
      body: ListView(
        children: <Widget>[
          Card(child: ListTile(title: Text('Viewable list sample'),
              onTap:(){Navigator.push(
                context,
                MaterialPageRoute(builder: (context) => GenListDisplay(entries: List<String>.generate(25, (i) => "Entry $i"),)),);})),
          Card(
            child: ListTile(
                title: Text('Data input sample'),
                onTap:(){Navigator.push(
                  context,
                  MaterialPageRoute(builder: (context) => InputName()),);}
            ),
          ),
          Card(
              child: ListTile(
                  title: Text('Random Number'),
                  onTap: (){Navigator.push(context, MaterialPageRoute(builder: (context) => RandomNumGen()),);}
              )
          ),
          Card(
            child: ListTile(
                title: Text('Display Hopkins Scale'),
                onTap: (){Navigator.push(context, MaterialPageRoute(builder: (context) => ImageDisplayer()),);}
            ),
          ),
          Card(
            child: ListTile(
                title: Text('Create Entry'),
                onTap: (){CreateEntry(context);}
            ),
          ),
        ],
      )
      /*Center(
        child: RaisedButton(
          child: Text("Sample Data input"),
          onPressed: (){
            Navigator.push(
              context,
              //MaterialPageRoute(builder: (context) => GenListDisplay(entries: List<String>.generate(25, (i) => "Entry $i"),)),
                MaterialPageRoute(builder: (context) => InputName()),
            );
          },
        ),
      )*/,
    );
  }
}

class SecondPage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Second Page'),
      ),
      body: Center(
        child: RaisedButton(
            onPressed: (){
              Navigator.pop(context);
            },
            child: Text('Back')
        ),
      ),
    );
  }
}

//generated strings to display a scrollable list.
class GenListDisplay extends StatelessWidget {
  final List<String> entries;
  GenListDisplay({Key key, @required this.entries}) : super(key: key);

  @override
  Widget build(BuildContext context){
    final title = 'Viewable Long list';
    return Scaffold(
      appBar: AppBar(title: Text(title),
      ),
      body: ListView.builder(
        itemCount: entries.length,
        itemBuilder: (context, index){
          return ListTile(title: Text('${entries[index]}'),
          );
        },
      ),
    );
  }
}

class InputName extends StatefulWidget {
  @override
  InputPageState createState() => new InputPageState();
}
class InputPageState extends State<InputName> {
  String username = "";
  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(title: Text('Input Data'),
        ),
        body: new Container(
          padding: EdgeInsets.all(20.0),
          child: new Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: <Widget>[
              new TextField(
                decoration: new InputDecoration(hintText: 'Data'),
                onChanged: (String textinput) {
                  setState((){
                    username = textinput;
                  });
                },
              ),
              new Text(username),
            ],
          ),
        ));
  }
}
class RandomNumGen extends StatefulWidget{
  @override
  RandomNumState createState() => new RandomNumState();
}

class RandomNumState extends State<RandomNumGen>{

  @override
  Widget build(BuildContext context) {
    var rand = new Random();
    var r = rand.nextInt(100000);
    return Scaffold(
      appBar: AppBar(title: Text('Random Number')
      ),
      body: new Container(
        padding: EdgeInsets.all(20.0),
        child: new Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            ListTile(
              title: Text('Random Number: $r'),
            )
          ],
        ),
      ),


    );
  }
}

class ImageDisplayer extends StatefulWidget{
  @override
  ImageDispState createState() => ImageDispState();
}

class ImageDispState extends State<ImageDisplayer>{
  @override
  Widget build(BuildContext context) {
    AssetImage('assets/images/Grade1.png');
    AssetImage('assets/images/Grade2.png');
    AssetImage('assets/images/Grade3.png');
    AssetImage('assets/images/Grade4.png');
    return Scaffold(
        appBar: AppBar(title: Text('Hopkins Scale')),
        body: new Container(
            padding: EdgeInsets.all(20.0),
            child: new Column(
                mainAxisAlignment: MainAxisAlignment.center,
                crossAxisAlignment: CrossAxisAlignment.center,
                children: <Widget>[
                  FlatButton(
                    onPressed: null,
                    padding: EdgeInsets.all(8),
                    child: Image.asset('images/Grade1.png'),
                  ),
                  FlatButton(
                    onPressed: null,
                    padding: EdgeInsets.all(8),
                    child: Image.asset('images/Grade2.png'),
                  ),
                  FlatButton(
                    onPressed: null,
                    padding: EdgeInsets.all(8),
                    child: Image.asset('images/Grade3.png'),
                  ),
                  FlatButton(
                    onPressed: null,
                    padding: EdgeInsets.all(8),
                    child: Image.asset('images/Grade4.png'),
                  )
                ]
            )
        )
    );
  }
}

CreateEntry(BuildContext context) {
  //Widget construction
  Widget noButton = FlatButton(
    child: Text("No"),
    onPressed: (){
      Navigator.of(context).pop(); // Removes the dialog box.
    },
  );
  Widget yesButton = FlatButton(
    child: Text("Yes"),
    onPressed: () { // A new entry will be created.
      Entry dataEntry = new Entry();
      EntryInjury(context, dataEntry);
      //Navigator.push(context, MaterialPageRoute(builder: (context) => TODO()),);
    },
  );

  AlertDialog alert = AlertDialog(
    title: Text("Did you fall?"),
    content: Text("Did you experince a fall?"),
    actions: [
      noButton,
      yesButton,
    ],
  );
  //Show the dialog box
  showDialog(
    context: context,
    builder: (BuildContext context){
      return alert;
    },
  );
}
EntryInjury(BuildContext context, Entry E) {
  //Widget construction
  Widget noButton = FlatButton(
    child: Text("No"),
    onPressed: (){
      E.setInjuried(false);
      Navigator.push(context, MaterialPageRoute(builder: (context) => EntryThirdScreen(E: E)),);
    },
  );
  Widget yesButton = FlatButton(
    child: Text("Yes"),
    onPressed: () {
      E.setInjuried(true);
      Navigator.push(context, MaterialPageRoute(builder: (context) => EntryThirdScreen(E: E)),);
    },
  );
  Widget cancelButton = FlatButton(
    child: Text("Cancel"),
    onPressed: () {
      //Navigator.of(context).popUntil(ModalRoute.withName('Main Page'));
      //Navigator.push(context, MaterialPageRoute(builder: (context) => TODO()),);
    },
  );
  AlertDialog alert = AlertDialog(
    title: Text("Injury"),
    content: Text("Did you experince an injury because of your fall?"),
    actions: [
      noButton,
      yesButton,
      cancelButton,

    ],
  );
  //Show the dialog box
  showDialog(
    context: context,
    builder: (BuildContext context){
      return alert;
    },
  );
}

//Third entry screen, the time of day for the fall.
class EntryThirdScreen extends StatelessWidget {
  final Entry E; //Container for the entry
  EntryThirdScreen({Key key, @required this.E}) : super(key: key);
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('What Time of day was your fall?'),
      ),
      body: ListView(
        children: <Widget>[
          Card(child: ListTile(title: Text('Morning'),
              onTap:(){
                E.setTimeDay("Morning");
                Navigator.push(context,
                  MaterialPageRoute(builder: (context) => ImageDisplayer()),);}
          ),
          ),
          Card(
            child: ListTile(
                title: Text('Daytime'),
                onTap:(){
                  E.setTimeDay("Daytime");
                  Navigator.push(context,
                    MaterialPageRoute(builder: (context) => ImageDisplayer()),);}
            ),
          ),
          Card(
              child: ListTile(
                  title: Text('Evening'),
                  onTap: (){
                    E.setTimeDay("Evening");
                    Navigator.push(context, MaterialPageRoute(builder: (context) => ImageDisplayer()),);}
              )
          ),
          Card(
            child: ListTile(
                title: Text('Night'),
                onTap: (){
                  E.setTimeDay("Night");
                  Navigator.push(context, MaterialPageRoute(builder: (context) => ImageDisplayer()),);}
            ),
          ),
        ],
      ),
    );
  }
}
