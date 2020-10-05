#include <iostream>
using std::cout;
using std::endl;

#include "comp_geo.h"

bool TestGetCircumference() {
  const double expected = 6.28319;
  double actual = GetCircumference(-1.0, -1.0, -2.0, -1.0);
  if (actual != expected) {
    cout << "Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}
bool TestGetVolume() {
  const double expected = 3.14159;
  double actual = GetVolume(-1.0, -1.0, -2.0, -1.0);
  if (actual != expected) {
    cout << "Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }
  return true;
}
bool TestGetPerimeter() {
  const double expected = 4.0;
  double actual = GetPerimeter(-1.0, -1.0, -2.0, -2.0);
  if (actual != expected) {
    cout << "Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}

bool TestGetDistanceSquared() {
  const double expected = 1.0;
  double actual = GetDistanceSquared(-1.0, -1.0, -2.0, -1.0);
  if (actual != expected) {
    cout << "Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}

bool TestGetDistance() {
  const double expected = 1.0;
  double actual = GetDistance(-1.0, -1.0, -2.0, -1.0);
  if (actual != expected) {
    cout << "Expected: " << expected << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}

int main(int argc, char* argv[]) {
  cout << "TestGetCircumference" << endl;
  if (!TestGetCircumference())
    return 1;
  cout << "TestGetPerimeter" << endl;
  if (!TestGetVolume())
    return 1;
  cout << "TestGetVolume" << endl;
  if (!TestGetPerimeter())
    return 1;
  cout << "TestGetDistanceSquared" << endl;
  if (!TestGetDistanceSquared())
    return 1;
  cout << "TestGetDistance" << endl;
  if (!TestGetDistance())
    return 1;

  return 0;
}
