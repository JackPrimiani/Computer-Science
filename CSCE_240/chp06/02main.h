/* Copyright 2018 */
#ifndef LECT_05INTRO_02MAIN_H_  // NOLINT
#define LECT_05INTRO_02MAIN_H_  // NOLINT

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
