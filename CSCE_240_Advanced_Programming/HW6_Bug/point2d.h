/*
Copyright 2018
Author: Jack Primiani
November 26th, 2018
*/

#include "vector2d.h" // NOLINT

#ifndef HW6_POINT2D_H_ // NOLINT
#define HW6_POINT2D_H_ // NOLINT

namespace csce240 {

class Point2d {
 public:
  static bool Collinear(const Point2d&, const Point2d&, const Point2d&);

  Point2d();
  Point2d(double, double);

  double x() const;
  double y() const;

 private:
  double x_;
  double y_;
};

}

#endif //  NOLINT
