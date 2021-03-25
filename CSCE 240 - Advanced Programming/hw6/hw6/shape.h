/*
Copyright 2018
Author: Jack Primiani
November 26, 2018
*/

#ifndef HW6_SHAPE_H_  // NOLINT
#define HW6_SHAPE_H_  // NOLINT

#include <math.h>
#include "vector2d.h"  // NOLINT

namespace csce240 {

class Shape {
 public:
  virtual ~Shape() { }
  virtual void Scale(double) { }
  virtual void Shift(const csce240::Vector2d&) { }
  virtual bool FPEq(double A, double B) {
    const double kMax_absolute_error = 0.0001;
    const double kMax_relative_error = 0.0001;
    if (fabs(A - B) < kMax_absolute_error) {
      return true;
    }
    double relative_error;
    if (fabs(B) > fabs(A)) {
      relative_error = fabs((A - B) / B);
    } else {
      relative_error = fabs((A - B) / A);
      }
    return (relative_error <= kMax_relative_error);
  }
};

}  // namespace csce240

#endif  // NOLINT
