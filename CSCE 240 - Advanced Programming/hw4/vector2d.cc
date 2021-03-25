/*
Copyright 2018
Author: Jack Primiani
October 18th, 2018
*/

#include "vector2d.h" //NOLINT

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

const Vector2d Vector2d::Add(const Vector2d& rhs) const {
  Vector2d Vadd(x_ + rhs.x_, y_ + rhs.y_);
  return Vadd;
}
const Vector2d Vector2d::Subtract(const Vector2d& rhs) const {
  Vector2d Vsub(x_ - rhs.x_, y_ - rhs.y_);
  return Vsub;
}
const Vector2d Vector2d::Reverse() const {
  Vector2d Vrev(x_ * -1, y_ * -1);
  return Vrev;
}
const Vector2d Vector2d::Scale(double scale) const {
  Vector2d Vscale(x_ * scale, y_ * scale);
  return Vscale;
}
bool Vector2d::EqualTo(const Vector2d& rhs) const {
  bool equ;
  if (x_ == rhs.x_ && y_ == rhs.y_) {
    equ = true;
  } else {
    equ = false;
  }
  return equ;
}
bool Vector2d::NotEqualTo(const Vector2d& rhs) const {
  return !(EqualTo(rhs));
}
double Vector2d::GetLength() const {
  double x = 0-x_;
  double y = 0-y_;
  double dist;
  x*=x;
  y*=y;
  dist = sqrt(x+y);
  return dist;
}

const Vector2d Vector2d::GetUnit() const {
  double len = GetLength();
  Vector2d Vunit(x_/len, y_/len);
  return Vunit;
}

const string Vector2d::ToString() const {
  stringstream sout;
  sout << "(" << std::to_string(x_) << ", " << std::to_string(y_) << ")";
  return sout.str();
}
