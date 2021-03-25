/* Copyright 2018 */
#ifndef _LECT_CHP06_DOLLAR_H_  // NOLINT
#define _LECT_CHP06_DOLLAR_H_  // NOLINT

#include <cassert>
// using assert
#include <cmath>
// using round
#include <iostream>
using std::istream;
using std::ostream;
#include <sstream>
using std::stringstream;
#include <string>
using std::string;

/* A class to hold dollars.
 *  - Whole dollars are stored as integers, cents are stored as floating points.
 */
class Dollar {
 public:
  /* Accepts a floating point value and returns a Dollar struct instance. */
  static const Dollar ToDollar(double val);

  // 1: Constructors for 0, 1 , or 2 parameters. These should be explicit
  Dollar() : dollars_(0), cents_(0.0) {}
  Dollar(double cents);
  Dollar(int dollars, double cents);

  /* Accepts a Dollar instance and returns a string value as
   * $[-]<int_value>.<int_value>, where the second int_value is in [0, 99]
   */
  const string ToString() const;

  /* Returns a new Dollar instance which represents the sum of lhs + rhs */
  const Dollar Add(const Dollar& rhs) const;

  ostream& Extract(ostream& out) const;
  istream& Insert(istream& in);
 private:
  // class members
  int dollars_;
  double cents_;
};



#endif  // NOLINT
