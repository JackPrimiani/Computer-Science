/* Copyright 2018 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;

#include "../chp11_2/stack.h"


void PrintStack(IntStack* stack) {
}

void FillStack(IntStack* stack, unsigned int size) {
}

void PrintVector(const vector<int>& vec) {
}

void FillVector(vector<int>* vec, unsigned int size) {
}

int main(int argc, char* argv[]) {
  vector<int> int_vector;

  FillVector(&int_vector, 10);
  PrintVector(int_vector);

  cout << "Testing IntStack:" << endl;
  IntStack int_stack;
  FillStack(&int_stack, 10);
  PrintStack(&int_stack);

  return 0;
}
