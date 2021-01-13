/* Copyright 2018 */

#include "02main.h"

/* Prompt
 *
 * Generates a menu to prompt user. Should be called before each loop
 * iteration.
 */
void Prompt() {
  cout << " 1.) Set first dollar variable.\n";
  cout << " 2.) Set second dollar variable.\n";
  cout << " 3.) Add variables and display.\n";
  cout << " 4.) Add double to First and display.\n";
  cout << " 5.) Quit." << endl;
  cout << " >>> ";
}

/* GetDollarInput
 *
 * Prompts user for double and creates and returns Dollar stuct.
 * Param:
 *  - a value allowing function's prompt to be aligned with menu/etc
 */
const Dollar GetDollarInput() {
  // prompt user for dollar value as floating point and assert it's non-negative
  Dollar value;
  cout << "Input dollar value as positive floating point: ";
  cin >> value;

  return value;
}

/* main */
int main(int argc, char* argv[]) {
  int input = 0;
  double buffer;
  Dollar first, second;

  cout << "Dollar Adder" << endl;  // Display app name
  do {
    // prompt and get input
    Prompt();
    cin >> input;

    // switch on input as indicated in prompt menu
    switch (input) {
    case 1:
      first = GetDollarInput();
      break;
    case 2:
      second = GetDollarInput();
      break;
    case 3: // display as <dollar> + <dollar> = <dollar>
      cout << first << " + " << second << " = " << (first + second) << endl;
      break;
    case 4:
      cout << "  Enter a floating point value: ";
      cin >> buffer;
      first = buffer + first;
      first.Extract(cout << "  First Dollar is ");
      break;
    case 5:
    default:
      cout << "  That is not a valid option.\n";
      break;
    }
    cout << endl; // emmit a blank line
  } while (input != 4);
}
