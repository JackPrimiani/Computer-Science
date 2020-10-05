/* Copyright 2018 */
#ifndef _CHP06_03MAIN_H_  // NOLINT
#define _CHP06_03MAIN_H_  // NOLINT

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;

#include "dollar.h"

/*Generates a menu to prompt user. Should be called before each loop
 * iteration.
 */
void Prompt();

/*
 * Prompts user for double and creates and returns Dollar stuct.
 * Param:
 *  - a value allowing function's prompt to be aligned with menu/etc
 */
const Dollar GetDollarInput();

#endif  // NOLINT
