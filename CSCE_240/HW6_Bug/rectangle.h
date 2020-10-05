/*
Copyright 2018
Author: Jack Primiani
November 26th, 2018
*/

#ifndef HW6_RECTANGLE_H_  // NOLINT
#define HW6_RECTANGLE_H_  // NOLINT

#include "shape.h"
#include "vector2d.h"
#include "point2d.h"
#include <iostream>
using std::cout;
using std::endl;

namespace csce240 {

class Rectangle: public Shape {
 public:
  inline Rectangle() {}
  Rectangle(Point2d ll, Point2d ur) : ll_(ll), ur_(ur) {}

  inline Point2d ll() const { return ll_; }
  inline Point2d ur() const { return ur_; }
  
  inline void llSet(Point2d ll) {  ll_ = ll; }
  inline void urSet(Point2d ur) {  ur_ = ur; }
  
  void Scale(double);
  void Shift(Vector2d&);
  
  bool operator==(Rectangle);
 private:
  Point2d ll_, ur_;
};

}

#endif  // NOLINT
