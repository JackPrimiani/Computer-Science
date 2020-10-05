/* Copyright 2018 */

#ifndef _LECT_CHP06_01MAIN_H_  // NOLINT
#define _LECT_CHP06_01MAIN_H_  // NOLINT

#include <cassert>
// using assert
#include <cmath>
// using round
// using 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <sstream>
using std::stringstream;
#include <string>
using std::string;

/*A passive structure to hold dollars as integer whole dollars and double
 * cents.
 *  - Per Google style guide, can only have the following members: constructor,
 *    destructor, Initialize(), Reset(), Validate()
 *  - Whole dollars are stored as integers, cents are stored as floating points.
 */
struct Dollar {
  // 1: Constructors for 0, 1 , or 2 parameters.

  // structure attributes
  int dollars;
  double cents; // holds a value in range [0.0, 100.0)

  bool positive;  // false when negative dollar amount
};

/* Returns a new Dollar instance which represents the sum of lhs + rhs */
const Dollar Add(const Dollar& lhs, const Dollar& rhs);

/* Accepts a floating point value and returns a Dollar struct instance. */
const Dollar ToDollar(double val);

/*Accepts a Dollar instance and returns a string value as
 *  $[-]<int>.<int>,
 * where the second int_value is in [0, 99]
 */
const string ToString(const Dollar& val);

/*Generates a menu to prompt user. Should be called before each loop
 * iteration.
 */
void Prompt();

/*
 * Prompts user for double and creates and returns Dollar stuct.
 * Param:
 *  - a value allowing function's prompt to be aligned with menu/etc
 */
const Dollar GetDollarInput();

#endif  // NOLINT
