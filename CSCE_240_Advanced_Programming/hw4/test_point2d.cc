/* Copyright 2018 */
#include "test_point2d.h"  //NOLINT


int main(int argc, char** argv) {
  if (!TestPointConstructAndAccess())
    return 1;

  if (!TestPointSubtract())
    return 1;

  if (!TestPointAdd())
    return 1;

  if (!TestPointEqualTo())
    return 1;

  if (!TestPointNotEqualTo())
    return 1;

  if (!TestPointDistanceToSquared())
    return 1;

  if (!TestPointDistanceTo())
    return 1;

  if (!TestPointToString())
    return 1;

  if (!TestPointExtract())
    return 1;

  if (!TestPointInsert())
    return 1;

  return 0;
}

bool TestPointConstructAndAccess() {
  Point2d p1, p2(1.5, 2.3);
  bool pass = p1.x() == 0.0 && p1.y() == 0.0 && p2.x() == 1.5 && p2.y() == 2.3;

  cout << "TestPointConstructAndAccess: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: 0, 0 Actual: "
      << p1.x() << ", " << p1.y() << endl
      << "  Expected: 1.5, 2.3 Actual: "
      << p2.x() << ", " << p2.y() << endl;

  return pass;
}

bool TestPointSubtract() {
  Point2d p1(1.0, -3.0), p2(0.5, 1.5);
  Vector2d v1 = p1.Subtract(p2);
  bool pass = v1.x() == 0.5 && v1.y() == -4.5;

  cout << "TestPointSubtract: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: 0.5, -4.5 Actual: "
      << v1.x() << ", " << v1.y() << endl;

  return pass;
}

bool TestPointAdd() {
  Point2d p1(0.0, 0.0), p2;
  Vector2d v1(4.0, 6.0);
  p2 = p1.Add(v1);
  bool pass = p2.x() == 4.0 && p2.y() == 6.0;

  cout << "TestPointAdd: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: 4, 6 Actual: "
      << p2.x() << ", " << p2.y() << endl;

  return pass;
}

bool TestPointEqualTo() {
  Point2d p1(1.0, 1.0), p2(1.0, 1.0);
  bool pass = p1.EqualTo(p2);

  cout << "TestPointEqualTo: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected (1.0, 1.0).EqualTo(1.0, 1.0): true Actual: "
      << (pass ? "true" : "false") << endl;

  return pass;
}

bool TestPointNotEqualTo() {
  Point2d p1(1.0, 1.0), p2(2.0, 1.0);
  bool pass = p1.NotEqualTo(p2);

  cout << "TestPointNotEqualTo: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected (1.0, 1.0).NotEqualTo(1.0, 1.0): false Actual: "
      << (p1.NotEqualTo(p1) ? "true" : "false") << endl;

  return pass;
}

bool TestPointDistanceToSquared() {
  Point2d p1(0.0, 0.0), p2(3.0, 4.0);
  bool pass = p1.DistanceToSquared(p2) == 25.0;

  cout << "TestPointDistanceToSquared: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected (0, 0), (3, 4): 25 Actual: "
      << p1.DistanceToSquared(p2) << endl;

  return pass;
}

bool TestPointDistanceTo() {
  Point2d p1(0.0, 0.0), p2(3.0, 4.0);
  bool pass = p1.DistanceTo(p2) == 5.0;

  cout << "TestPointDistanceTo: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected (0, 0) to (3, 4): 5 Actual: " << p1.DistanceTo(p2)
      << endl;

  return pass;
}

bool TestPointToString() {
  Point2d p(3.7, -8.1);
  bool pass = "(3.700000, -8.100000)" == p.ToString();

  cout << "TestPointToString: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: (3.700000, -8.100000) Actual: "
      << p.ToString() << endl;

  return pass;
}

bool TestPointExtract() {
  Point2d p(34.8, 23.9);
  stringstream sout;
  p.Extract(sout);
  bool pass = sout.str() == "(34.8, 23.9)";

  cout << "TestPointExtract: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: (34.8, 23.9) Actual: " << sout.str() << endl;

  return true;
}

bool TestPointInsert() {
  Point2d p;
  stringstream sin("3.0 4.0");
  p.Insert(sin);
  bool pass = 3.0 == p.x() && 4.0 == p.y();

  cout << "TestPointInsert: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: (3.000000, 4.000000) Actual: "
      << p.x() << ", " << p.y() << endl;

  return pass;
}

