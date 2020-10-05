/*
Copyright 2018
Author: Jack Primiani
November 12, 2018
*/

#ifndef HW5_POINT2D_H_  // NOLINT
#define HW5_POINT2D_H_  // NOLINT

#include <cmath>
#include <iostream>
using std::istream;
using std::ostream;
#include <string>
using std::string;
#include <sstream>
using std::stringstream;

#include "vector2d.h"  // NOLINT

class Point2d {
 public:
  Point2d() : x_(0.0), y_(0.0) {}
  Point2d(double x, double y) : x_(x), y_(y) {}

  inline double x() const { return x_; }
  inline double y() const { return y_; }

  const Point2d operator+(const Vector2d&) const;
  const Vector2d operator-(const Point2d&) const;
  bool operator==(const Point2d&) const;
  bool operator!=(const Point2d&) const;

  ostream& Extract(ostream& out) const;
  istream& Insert(istream& in);

 private:
  double x_;
  double y_;
};

ostream& operator<<(ostream& lhs, Point2d rhs);
istream& operator>>(istream& lhs, Point2d& rhs);

class CompareLeftToRight {
 public:
  bool operator()(Point2d lhs, Point2d rhs);
 private:
};

class CompareDistanceFrom {
 public:
  CompareDistanceFrom(Point2d from) : from_(from) {}
  bool operator()(Point2d lhs, Point2d rhs);
 private:
  Point2d from_;
};

#endif //  NOLINT
