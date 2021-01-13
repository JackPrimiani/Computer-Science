/*
Copyright 2018
Author: Jack Primiani
October 24th, 2018
*/

#include <cmath>
#include <iostream>
using std::istream;
using std::ostream;
#include <string>
using std::string;
#include <sstream>
using std::stringstream;

#include "vector2d.h" // NOLINT

#ifndef HW4_POINT2D_H_ // NOLINT
#define HW4_POINT2D_H_ // NOLINT

class Point2d {
 public:
  static bool Collinear(const Point2d&, const Point2d&, const Point2d&);

  Point2d();
  Point2d(double, double);

  double x() const;
  double y() const;

  const Point2d Add(const Vector2d&) const;
  const Vector2d Subtract(const Point2d&) const;

  bool EqualTo(const Point2d&) const;
  bool NotEqualTo(const Point2d&) const;

  double DistanceToSquared(const Point2d&) const;
  double DistanceTo(const Point2d&) const;

  const string ToString() const;

  ostream& Extract(ostream&) const;
  istream& Insert(istream&);

 private:
  double x_;
  double y_;
};
#endif //  NOLINT
