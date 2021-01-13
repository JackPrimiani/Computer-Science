/* copyright 2018 */

#include <iostream>
using std::cout;
using std::endl;

#include "../hw6/circle.h"
#include "../hw6/point2d.h"
#include "../hw6/rectangle.h"
#include "../hw6/shape.h"
#include "../hw6/vector2d.h"
using namespace csce240;

/*
bool TestScaleCircle() {
  Circle actual(Point2d(), 1.5), expected(Point2d(), 3.5);
  const double scalar = 2.0;

  Shape *shape = &actual;
  shape->Scale(scalar);

  if (!(actual == expected)) {
    cout << "TestScaleCircle FAILED" << endl;

    return false;
  }

  return true;
}

bool TestShiftCircle() {
  Circle actual(Point2d(), 1.0), expected(Point2d(1.0, 1.0), 1.0);
  const Vector2d offset(1.0, 1.0);

  Shape *shape = &actual;
  shape->Shift(offset);

  if (!(actual == expected)) {
    cout << "TestShiftCircle FAILED" << endl;

    return false;
  }

  return true;
}
*/
bool TestScaleRectangle() {
  Rectangle actual(Point2d(-1, -1), Point2d(1, 1)),
      expected(Point2d(-2.5, -2.5), Point2d(2.5, 2.5));
  const double scalar = 1.5;

  Shape *shape = &actual;
  shape->Scale(scalar);

  if (!(actual == expected)) {
    cout << "TestShiftCircle FAILED" << endl;

    return false;
  }

  return true;
}
/*
bool TestShiftRectangle() {
  Rectangle actual(Point2d(-1, -1), Point2d(1, 1)),
      expected(Point2d(-1, 1), Point2d(1, 3));
  const Vector2d offset(0, 2);

  Shape *shape = &actual;
  shape->Shift(offset);

  if (!(actual == expected)) {
    cout << "TestShiftCircle FAILED" << endl;

    return false;
  }

  return true;

}
*/
int main(int argc, char* argv[]) {
/*
  if (!TestScaleCircle())
    return 1;
  if (!TestShiftCircle())
    return 1;
*/
  if (!TestScaleRectangle())
    return 1;
/*
  if (!TestShiftRectangle())
    return 1;
*/
  return 0;
}

/*
bool FPEq(double A, double B) {
// Tests two floating point numbers for near-equality usually using the
// relative error, but also with a lower bound on the absolute error for
// numbers to be considered different.
//
// This code is based on Bruce Dawson's "Comparing Floating Point Numbers" at
// http://www.cygnus-software.com/papers/comparingfloats/comparingfloats.htm.

  const double kMax_absolute_error = 0.0001;
  const double kMax_relative_error = 0.0001;


  if (fabs(A - B) < kMax_absolute_error) { 
    return true;
  }

  double relative_error;
  
  if (fabs(B) > fabs(A)) {
    relative_error = fabs((A - B) / B);
  } else {
    relative_error = fabs((A - B) / A);
    }

  return (relative_error <= kMax_relative_error);
}
*/
