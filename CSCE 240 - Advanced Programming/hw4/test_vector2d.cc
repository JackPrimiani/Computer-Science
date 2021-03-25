/* Copyright 2018 */
#include "test_vector2d.h"  //NOLINT


int main(int argc, char** argv) {
  if (!TestVectorCreateAndAccess())
    return 1;

  if (!TestVectorAdd())
    return 1;

  if (!TestVectorSubtract())
    return 1;

  if (!TestVectorReverse())
    return 1;

  if (!TestVectorScale())
    return 1;

  if (!TestVectorEqualTo())
    return 1;

  if (!TestVectorNotEqualTo())
    return 1;

  if (!TestVectorGetLength())
    return 1;

  if (!TestVectorGetUnit())
    return 1;

  if (!TestVectorToString())
    return 1;

  return 0;
}

bool TestVectorCreateAndAccess() {
  Vector2d v1, v2(1.5, 2.3);
  bool pass = v1.x() == 0.0 && v1.y() == 0.0
      && v2.x() == 1.5 && v2.y() == 2.3;

  cout << "TestVectorCreateAndAccess:"
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: 0, 0 Actual: "
      << v1.x() << ", " << v1.y() << endl
      << "  Expected: 1.5, 2.3 Actual: "
      << v2.x() << ", " << v2.y() << endl;

  return pass;
}

bool TestVectorAdd() {
  Vector2d v1(1.7, -3.0), v2(2.1, 1.5);
  Vector2d t1 = v1.Add(v2);
  bool pass = t1.x() == 3.8 && t1.y() == -1.5;

  cout << "TestVectorAdd: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: 3.8, -1.5 Actual: "
      << t1.x() << ", " << t1.y() << endl;

  return pass;
}

bool TestVectorSubtract() {
  Vector2d v1(1.0, -3.0), v2(0.5, 1.5);
  Vector2d t1 = v1.Subtract(v2);
  bool pass = t1.x() == 0.5 && t1.y() == -4.5;

  cout << "TestVectorSubtract"
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: 0.5, -4.5 Actual: "
      << t1.x() << ", " << t1.y() << endl;

  return pass;
}

bool TestVectorReverse() {
  Vector2d v(-1.0, 2.0);

  Vector2d nv1 = v.Reverse();
  bool pass = nv1.x() == 1.0 && nv1.y() == -2.0;

  cout << "TestVectorReverse"
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: 1, -2 Actual: "
      << nv1.x() << ", " << nv1.y() << endl;
  return pass;
}

bool TestVectorScale() {
  Vector2d v1(2.0, 4.0);
  Vector2d v2 = v1.Scale(2.0);
  bool pass = v2.x() == 4.0 && v2.y() == 8.0;

  cout << "TestVectorScale"
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected 4, 8 Actual: "
      << v2.x() << ", " << v2.y() << endl;

  return pass;
}

bool TestVectorEqualTo() {
  Vector2d v1(1.0, 1.0), v2(1.0, 1.0);
  bool pass = v1.EqualTo(v2);

  cout << "TestVectorEqualTo: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected (1.0, 1.0) == (1.0, 1.0): 1 Actual: "
      << v1.EqualTo(v2) << endl;

  return pass;
}

bool TestVectorNotEqualTo() {
  Vector2d v1(1.0, 1.0), v2(2.0, 1.0);
  bool pass = v1.NotEqualTo(v2);

  cout << "TestVectorNotEqualTo: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected (1.0, 1.0) != (2.0, 1.0): 0 Actual: "
      << v1.NotEqualTo(v2) << endl;

  return pass;
}

bool TestVectorGetLength() {
  Vector2d v1(3, 4);
  bool pass = v1.GetLength() == 5;

  cout << "TestVectorGetLength: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected |(3, 4)|: 5 Actual: " << v1.GetLength() << endl;

  return pass;
}

bool TestVectorGetUnit() {
  Vector2d v1(3, 4), v2 = v1.GetUnit();
  bool pass = v2.x() == 0.6 && v2.y() == 0.8;

  cout << "TestVectorGetUnit: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected (3, 4).GetUnit(): (0.6, 0.8) Actual: "
      << "(" << v2.x() << ", " << v2.y() << ")" << endl;

  return pass;
}

bool TestVectorToString() {
  Vector2d v(3.7, -8.1);
  bool pass = "(3.700000, -8.100000)" == v.ToString();

  cout << "TestVectorToString: "
      << (pass ? "PASSED" : "FAILED") << endl
      << "  Expected: (3.700000, -8.100000) Actual: "
      << v.ToString() << endl;

  return pass;
}


