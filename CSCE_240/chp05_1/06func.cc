/*
 * Copyright 2018
 * Created by Jeremy S Lewis
 */
#include "06func.h"

int MinValue(int array[], int size) {
  assert(0 < size);
  int smallest = array[0];

  for (int i = 1; i < size; ++i)
    if (smallest > array[i])
      smallest = array[i];

  return smallest;
}

int* copy(int from[], int size){
  double value = 0.0;
  int *to = new int[size];
  for (int i =0; i < size; i++){
    to[i] = from[i];
  }
  return to;
}

int main(int argc, char* argv[]) {
  // test array functions
  int array[] = {9, -1, 3, -2, 33};
  cout << "Smallest is " << MinValue(array, 0) << endl;
  return 0;
}
