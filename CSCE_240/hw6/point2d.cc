/*
Copyright 2018
Author: Jack Primiani
November 26th, 2018
*/

#include "point2d.h" //NOLINT
#include "vector2d.h" //NOLINT
namespace csce240 {

Point2d::Point2d() {
  this->x_ = 0.0;
  this->y_ = 0.0;
}

Point2d::Point2d(double x, double y) {
  this->x_ = x;
  this->y_ = y;
}

double Point2d::x() const {
  return x_;
}

double Point2d::y() const {
  return y_;
}

}   // namespace csce240
