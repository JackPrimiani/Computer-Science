/*
Copyright 2018
Author: Jack Primiani
November 26th, 2018
*/

#include "vector2d.h" //NOLINT

namespace csce240 {

Vector2d::Vector2d() {
  x_ = 0.0;
  y_ = 0.0;
}
Vector2d::Vector2d(double x, double y) {
  x_ = x;
  y_ = y;
}

double Vector2d::x() const {
  return x_;
}
double Vector2d::y() const {
  return y_;
}

double Vector2d::GetLength() const {
  double Vx = 0-x();
  double Vy = 0-y();
  double dist;
  Vx*=Vx;
  Vy*=Vy;
  dist = sqrt(Vx+Vy);
  return dist;
}

}
