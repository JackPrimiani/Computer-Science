/* Copyright 2018 */
#ifndef _240_HW4_TEST_POINT2D_H_  //NOLINT
#define _240_HW4_TEST_POINT2D_H_  //NOLINT

#include <iostream>
using std::endl;
using std::cin;
using std::cout;
#include <sstream>
using std::stringstream;

#include "point2d.h"  //NOLINT
#include "vector2d.h"  //NOLINT

bool TestPointConstructAndAccess();
bool TestPointSubtract();
bool TestPointAdd();
bool TestPointEqualTo();
bool TestPointNotEqualTo();
bool TestPointDistanceToSquared();
bool TestPointDistanceTo();
bool TestPointToString();
bool TestPointExtract();
bool TestPointInsert();

int main(int argc, char** argv);

#endif  //NOLINT
