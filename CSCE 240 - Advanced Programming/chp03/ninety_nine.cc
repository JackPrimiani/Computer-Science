/* ninety_nine Copyright 2018
 *
 * Write the 99 stanzas of "Ninety-Nine Bottles of Beer on the Wall" song to
 * the console.
 *
 * Write a void function with id PrintStanza which accepts an integer n, and
 * prints
 *  n bottles of beer on the wall,
 *  n bottles of beer,
 *  Take one down, pass it around,
 *  n - 1 bottles of beer on the wall
 * Where n and n - 1 are in English. Implement it with the functions defined
 * below and print the 99 stanzas in a loop.
 * 
 * Write a function with id InEnglish which accepts an integer and returns the
 * value in a string as an English word [Zero to Ninety-nine]. Implement
 * function with functions described below. Test the function.
 *
 * Write a function with id OnesInEnglish which accepts an integer in [0,
 * 9] and returns a string containing the value as an English word. Test the
 * function.
 *
 * Write a function with id TensInEnglish which accepts an integer n in [10,
 * 90] s.t. n % 10 = 0 and returns a string containing the value as an English
 * word. Test the function.
 *
 * Write a function with id TeensInEnglish which accepts an integer in [10, 19]
 * and returns a string containing the value as an English word. Test the
 * function.
 */
#include <string>
using std::string

string OnesInEnglish(int n){
  switch(n) {
  case 0:
    return "Zero";
  case 1:
    return "One";
  case 2:
    return "Two";
  case 3:
    return "Three";

  }
}

string TensInEnglish(int n) {
  switch (n / 10) {
  case 2:
    return "Twenty";
  case 3:
    return "Thirty";
  case 4:
    return "Forty";
  }
}  



