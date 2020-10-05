/*
Copyright 2018
Author: Jack Primiani
November 26th, 2018
*/

#include "circle.h"  // NOLINT
#include "shape.h"  // NOLINT
#include "vector2d.h"  // NOLINT
#include "point2d.h"  // NOLINT 

void csce240::Circle::Scale(double scalar) {
  radiusSet(this->radius()+scalar);
}
void csce240::Circle::Shift(const Vector2d& offset) {
  Point2d newCenter(this->center().x()+offset.x(),
    this->center().y()+offset.y());
  centerSet(newCenter);
}
bool csce240::Circle::operator==(Circle that) {
  bool c1 = FPEq(center_.x(), that.center().x());
  bool c2 = FPEq(center_.y(), that.center().y());
  bool c3 = FPEq(radius(), that.radius());
  return c1 && c2 && c3;
}
