/*
Copyright 2018
Author: Jack Primiani
November 12, 2018
*/

#ifndef HW5_VECTOR2D_H_ //  NOLINT
#define HW5_VECTOR2D_H_ //  NOLINT

#include <cmath>
#include <iostream>
using std::istream;
using std::ostream;
#include <string>
using std::string;
#include <sstream>
using std::stringstream;

class Vector2d {
 public:
  Vector2d() : x_(0.0), y_(0.0) {}
  Vector2d(double x, double y) : x_(x), y_(y) {}

  inline double x() const { return x_; }
  inline double y() const { return y_; }

  const Vector2d operator+(const Vector2d&) const;
  const Vector2d operator-(const Vector2d&) const;
  const Vector2d operator-() const;
  const Vector2d operator*(double) const;
  bool operator==(const Vector2d&) const;
  bool operator!=(const Vector2d&) const;
  ostream& Extract(ostream&) const;
  istream& Insert(istream&);

 private:
  double x_;
  double y_;
};

Vector2d operator*(double lhs, Vector2d rhs);
ostream& operator<<(ostream& lhs, Vector2d rhs);
istream& operator>>(istream& lhs, Vector2d& rhs);

class CompareMagnitude {
 public:
  bool operator()(Vector2d lhs, Vector2d rhs);
 private:
};

class CompareDirection {
 public:
  bool operator()(Vector2d lhs, Vector2d rhs);
 private:
};

#endif //  NOLINT
