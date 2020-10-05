/*
Copyright 2018
Author: Jack Primiani
November 12th, 2018
*/

#include "point2d.h"  // NOLINT
#include "vector2d.h"  // NOLINT

const Point2d Point2d::operator+(const Vector2d& rhs) const {
  double x = this->x_ + rhs.x();
  double y = this->y_ + rhs.y();
  Point2d Padd(x, y);
  return Padd;
}
const Vector2d Point2d::operator-(const Point2d& rhs) const {
  double x = this->x_ - rhs.x();
  double y = this->y_ - rhs.y();
  Vector2d Psub(x, y);
  return Psub;
}
bool Point2d::operator==(const Point2d& rhs) const {
  bool equ;
  if (this->x_ == rhs.x_ && this->y_ == rhs.y_) {
    equ = true;
  } else {
    equ = false;
  }
  return equ;
}
bool Point2d::operator!=(const Point2d& rhs) const {
  bool equ;
  if (this->x_ == rhs.x_ && this->y_ == rhs.y_) {
    equ = true;
  } else {
    equ = false;
  }
  return !equ;
}
ostream& Point2d::Extract(ostream& out) const {
  out << "(" << x_ << ", " << y_ << ")";
  return out;
}
istream& Point2d::Insert(istream& in) {
  in >> x_ >> y_;
  return in;
}
ostream& operator<<(ostream& lhs, Point2d rhs) {
  return rhs.Extract(lhs);
}
istream& operator>>(istream& lhs, Point2d& rhs) {
  return rhs.Insert(lhs);
}
bool CompareLeftToRight::operator()(Point2d lhs, Point2d rhs) {
  if (lhs.x() < rhs.x()) {
    return true;
  } else if (lhs.x() > rhs.x()) {
    return false;
  } else if (lhs.x() == rhs.x()) {
    if (lhs.y() < rhs.y()) {
      return true;
    } else if (lhs.y() > rhs.y()) {
      return false;
    }
  }
  return 0;
}
bool CompareDistanceFrom::operator()(Point2d lhs, Point2d rhs) {
  bool ret;
  double x = from_.x()-lhs.x();
  double y = from_.y()-lhs.y();
  double dist1, dist2;
  x*=x;
  y*=y;
  dist1 = sqrt(x+y);
  x = from_.x()-rhs.x();
  y = from_.y()-rhs.y();
  x*=x;
  y*=y;
  dist2 = sqrt(x+y);
  return (dist1 < dist2);
}
