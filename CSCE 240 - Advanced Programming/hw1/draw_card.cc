/*
Copyright [2018] 
Author:Jack Primiani
September 16th, 2018
*/

#include <cstdlib>
// using rand
// using srand
#include <ctime>
// using time
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

string assignNum(int randCard) {
    switch (randCard) {
    case 0:
      return "2";
    case 1:
      return "3";
    case 2:
      return "4";
    case 3:
      return "5";
    case 4:
      return "6";
    case 5:
      return "7";
    case 6:
      return "8";
    case 7:
      return "9";
    case 8:
      return "10";
    case 9:
      return "J";
    case 10:
      return "Q";
    case 11:
      return "K";
    case 12:
      return "A";
  }
}

string assignSuit(int randCard) {
    switch (randCard) {
    case 0:
      return "S";
    case 1:
      return "H";
    case 2:
      return "D";
    case 3:
      return "C";
  }
}

int main(int argc, char* argv[]) {
  int srand(time(NULL));
  int inp, i, randCard;
  cin >> inp;
  for (i = 0; i < inp; i++) {
    cout << assignNum(rand() % 13) << assignSuit(rand() % 4) << " ";
  }
  cout << "" << endl;
  return 0;
}
