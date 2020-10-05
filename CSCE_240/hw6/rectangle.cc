/*
Copyright 2018
Author: Jack Primiani
November 26th, 2018
*/

#include "rectangle.h"  // NOLINT
#include "shape.h"  // NOLINT
#include "vector2d.h"  // NOLINT
#include "point2d.h"  // NOLINT

void csce240::Rectangle::Scale(double scalar) {
  Point2d urScale(ur_.x()+scalar, ur_.y()+scalar);
  Point2d llScale(ll_.x()-scalar, ll_.y()-scalar);
  urSet(urScale);
  llSet(llScale);
}

void csce240::Rectangle::Shift(const Vector2d& offset) {
  Point2d urScale(ur_.x()+offset.x(), ur_.y()+offset.y());
  Point2d llScale(ll_.x()+offset.x(), ll_.y()+offset.y());
  urSet(urScale);
  llSet(llScale);
}

bool csce240::Rectangle::operator==(Rectangle that) {
  bool c1 = FPEq(ur_.x(), that.ur().x());
  bool c2 = FPEq(ur_.y(), that.ur().y());
  bool c3 = FPEq(ll_.x(), that.ll().x());
  bool c4 = FPEq(ll_.y(), that.ll().y());
  return c1 && c2 && c3 && c4;
}
