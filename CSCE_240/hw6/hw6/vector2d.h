/*
Copyright 2018
Author: Jack Primiani
November 26th, 2018
*/

#ifndef HW6_VECTOR2D_H_ // NOLINT
#define HW6_VECTOR2D_H_ // NOLINT
#include <cmath>

namespace csce240 {

class Vector2d {
 public:
  Vector2d();
  Vector2d(double, double);

  double x() const;
  double y() const;
  double GetLength() const;
 private:
  double x_;
  double y_;
};

}  // namespace csce240

#endif //  NOLINT
