/*
Copyright 2018
Author: Jack Primiani
October 2nd, 2018
*/

#ifndef HW4_VECTOR2D_H_ // NOLINT
#define HW4_VECTOR2D_H_ // NOLINT

#include <cmath>
#include <sstream>
using std::stringstream;
#include <string>
using std::string;

class Vector2d {
 public:
  Vector2d();
  Vector2d(double, double);

  double x() const;
  double y() const;

  const Vector2d Add(const Vector2d&) const;
  const Vector2d Subtract(const Vector2d&) const;

  const Vector2d Reverse() const;

  const Vector2d Scale(double) const;

  bool EqualTo(const Vector2d&) const;
  bool NotEqualTo(const Vector2d&) const;

  double GetLength() const;

  const Vector2d GetUnit() const;

  const string ToString() const;

 private:
  double x_;
  double y_;
};
#endif //  NOLINT
