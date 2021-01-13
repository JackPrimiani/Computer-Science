/*
Copyright 2018
Author: Jack Primiani
November 26th, 2018
*/

#include "rectangle.h"
#include "shape.h"
#include "vector2d.h"
#include "point2d.h"

void csce240::Rectangle::Scale(double scalar){
  Point2d urScale(ur_.x()+scalar, ur_.y()+scalar);
  Point2d llScale(ll_.x()-scalar, ll_.y()-scalar);
  urSet(urScale);
  llSet(llScale);
}

void csce240::Rectangle::Shift(Vector2d& offset){
  double scalar = offset.GetLength();
  Point2d urScale(ur_.x()+scalar, ur_.y()+scalar);
  Point2d llScale(ll_.x()+scalar, ll_.y()+scalar);
  urSet(urScale);
  llSet(llScale);
}
  
bool csce240::Rectangle::operator==(Rectangle that){
/*
  bool c1 = csce240::FPEq(ur_.x(), that.ur().x());
  bool c2 = csce240::FPEq(ur_.y(), that.ur().y());
  bool c3 = csce240::FPEq(ll_.x(), that.ll().x());
  bool c4 = csce240::FPEq(ll_.y(), that.ll().y());
  return c1 && c2 && c3 && c4;
*/
  return 0;

}
