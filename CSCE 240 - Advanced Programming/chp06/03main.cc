/* Copyright 2018 */

#include "03main.h"

/* Prompt
 *
 * Generates a menu to prompt user. Should be called before each loop
 * iteration.
 */
void Prompt() {
  cout << " 1.) Append dollar variable.\n";
  cout << " 2.) Set dollar variable.\n";
  cout << " 3.) Sum variables and display.\n";
  cout << " 4.) Quit." << endl;
  cout << " >>> ";
}

/* GetDollarInput
 *
 * Prompts user for double and creates and returns Dollar stuct.
 * Param:
 *  - a value allowing function's prompt to be aligned with menu/etc
 */
const Dollar GetDollarInput() {
  // prompt user for dollar value as floating point and assert it is
  //   non-negative
  double value;
  cout << "Input dollar value as non-negative floating point: ";
  cin >> value;

  return Dollar::ToDollar(value);
}

/* main */
int main(int argc, char* argv[]) {
  int input = 0;
  Dollar first, second;

  cout << "Dollar Adder" << endl;  // Display app name
  do {
    // prompt and get input
    Prompt();
    cin >> input;

    // switch on input as indicated in prompt menu
    switch (input) {
    case 1:
      // append dollar variable to vector
      break;
    case 2:
      // prompt and set dollar value, write function
      break;
    case 3: 
      // display as Sum(<dollar>, ...) = <dollar>
      break;
    case 4:
      break;
    default:
      cout << "  That is not a valid option.\n";
      break;
    }


    cout << endl; // emmit a blank line
  } while (input != 4);
}
