/* Copyright 2018 */
#ifndef _240_HW4_TEST_VECTOR2D_H_  //NOLINT
#define _240_HW4_TEST_VECTOR2D_H_  //NOLINT

#include <iostream>
using std::endl;
using std::cout;

#include "vector2d.h"  //NOLINT

bool TestVectorCreateAndAccess();
bool TestVectorAdd();
bool TestVectorSubtract();
bool TestVectorReverse();
bool TestVectorScale();
bool TestVectorEqualTo();
bool TestVectorNotEqualTo();
bool TestVectorGetLength();
bool TestVectorGetUnit();
bool TestVectorToString();

int main(int argc, char** argv);

#endif  //NOLINT
