/*
Copyright 2018
Author: Jack Primiani
October 18th, 2018
*/

#include "point2d.h" //NOLINT
#include "vector2d.h" //NOLINT

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

const Point2d Point2d::Add(const Vector2d& rhs) const {
  double x = this->x_ + rhs.x();
  double y = this->y_ + rhs.y();
  Point2d Padd(x, y);
  return Padd;
}

const Vector2d Point2d::Subtract(const Point2d& rhs) const {
  double x = this->x_ - rhs.x();
  double y = this->y_ - rhs.y();
  Vector2d Psub(x, y);
  return Psub;
}

bool Point2d::EqualTo(const Point2d& rhs) const {
  bool equ;
  if (this->x_ == rhs.x_ && this->y_ == rhs.y_) {
    equ = true;
  } else {
    equ = false;
  }
  return equ;
}

bool Point2d::NotEqualTo(const Point2d& rhs) const {
  return !(EqualTo(rhs));
}

double Point2d::DistanceToSquared(const Point2d& rhs) const {
  double x = rhs.x_-x_;
  double y = rhs.y_-y_;
  double dist;
  x*=x;
  y*=y;
  dist = x+y;
  return dist;
}

double Point2d::DistanceTo(const Point2d& rhs) const {
  double dist = sqrt(DistanceToSquared(rhs));
  return dist;
}

const string Point2d::ToString() const {
  stringstream sout;
  std::string xS = std::to_string(x_);
  std::string yS = std::to_string(y_);
  sout << "(" << xS << ", " << yS << ")";
  return sout.str();
}

ostream& Point2d::Extract(ostream& out) const {
  out << "(" << x_ << ", " << y_ << ")";
  return out;
}

istream& Point2d::Insert(istream& in) {
  in >> x_ >> y_;
  return in;
}
