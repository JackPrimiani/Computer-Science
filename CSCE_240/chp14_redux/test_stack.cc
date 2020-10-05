/* Copyright 2018 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;

#include "../chp14/ppt.h"
using csce240::PPT;
#include "../chp14/stack.h"
using csce240::IntStack;


void PrintStack(IntStack* stack) {
}

void FillStack(unsigned int size, IntStack* stack) {
}

void PrintVector(const vector<int>& vec) {
  for (size_t i = 0; i < vec.size(); ++i)
    cout << vec.at(i) << " ";
}

void FillVector(unsigned int size, vector<int>* vec) {
  for (unsigned int i = 0; i < size; ++i)
    vec->push_back(i + 1);
}


int main(int argc, char* argv[]) {
  vector<int> int_vector;

  FillVector(10, &int_vector);
  IntStack int_stack(int_vector);
  PPT *ppt;
  ppt = new IntStack(int_vector);
  PrintVector(int_vector);
  cout << endl;
  PrintVector(int_stack);
  cout << endl;
  return 0;

  cout << "Testing IntStack:" << endl;
  FillStack(10, &int_stack);
  PrintStack(&int_stack);

  return 0;
}
