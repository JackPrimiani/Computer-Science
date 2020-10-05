/*
Copyright 2018
Author: Jack Primiani
November 26th, 2018
*/

#ifndef HW6_CIRCLE_H_  // NOLINT
#define HW6_CIRCLE_H_  // NOLINT

#include <iostream>
using std::cout;
using std::endl;

#include "shape.h"  // NOLINT
#include "vector2d.h"  // NOLINT
#include "point2d.h"  // NOLINT

namespace csce240 {

class Circle: public Shape {
 public:
  inline Circle() {}
  Circle(Point2d center, double radius) : center_(center), radius_(radius) {}

  inline Point2d center() const { return center_; }
  inline double radius() const { return radius_; }

  inline void centerSet(Point2d center) { center_ = center; }
  inline void radiusSet(double radius) { radius_ = radius; }

  void Scale(double);
  void Shift(const Vector2d&);

  bool operator==(Circle);
 private:
  Point2d center_;
  double radius_;
};

}  // NOLINT

#endif  // NOLINT
