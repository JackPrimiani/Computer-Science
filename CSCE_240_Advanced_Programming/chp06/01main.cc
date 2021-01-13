/* Copyright 2018 */
#include "01main.h"

const Dollar Add(const Dollar& lhs, const Dollar& rhs) {
  Dollar sum;
  sum.dollars = lhs.dollars + rhs.dollars;
  sum.cents = lhs.cents + rhs.cents;
  
  if (sum.cents >= 100.0) {
    sum.cents -= 100.00;
    ++sum.dollars;
  }

  return sum;
}

const Dollar ToDollar(double val) {
  Dollar dollar;

  // when negative, make positive and mark Dollar negative
  if (0 > val) {
    val = fabs(val);
    dollar.positive = true;
  } else
    dollar.positive = false;

  dollar.dollars = static_cast<int>(val);
  dollar.cents = 100.0*(val - dollar.dollars);

  return dollar;
}

const string ToString(const Dollar& val) {
  stringstream sout;

  sout << "$";
 
  int cents = static_cast<int>(round(val.cents));
  if (100 <= cents) {
    sout << (val.dollars + 1);
    cents -= 100;
  } else
    sout << val.dollars;

  sout << '.';

  if (10 > cents)
    sout << 0;
  sout << cents;

  return sout.str();
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
      first = GetDollarInput();
      break;
    case 2:
      second = GetDollarInput();
      break;
    case 3: // display as <dollar> + <dollar> = <dollar>
      cout << ToString(first) << " + " << ToString(second) << " = "
          << ToString(Add(first, second)) << endl;
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

/* Prompt */
void Prompt() {
  cout << " 1.) Set first dollar variable.\n";
  cout << " 2.) Set second dollar variable.\n";
  cout << " 3.) Add variables and display.\n";
  cout << " 4.) Quit." << endl;
  cout << " >>> ";
}


/* GetDollarInput */
const Dollar GetDollarInput() {
  // prompt user for dollar value as floating point
  cout << "Input dollar value as positive floating point: ";

  double value;
  cin >> value;

  return ToDollar(value);
}

