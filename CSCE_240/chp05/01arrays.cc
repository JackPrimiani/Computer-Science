/*
 * Copyright 2018
 * Created by Jeremy S Lewis
 */

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char** argv) {
  // create a const int to hold the size of the array
  const int kSize = 10;

  // use the const int to create an array
  int arr[kSize];

  // store integers 1 to n in the array, where n is the size of the array
  for (int i = 0; i < kSize; ++i)
    arr[i] = i + 1;

  // determine the sum of the n integers stored in the array
  int sum = 0;
  for (int i = 0; i < kSize; ++i)
    sum += arr[i];
  // display the sum
  cout << "Sum: " << sum << endl;

  // create a second array and copy each value, doubled, from the first
  int arr2[kSize];
  for (int i = 0; i < kSize; ++i)
    arr2[i] = 2*arr[i];

  // display both arrays in columns, 1 element of each per line, tab delimited
  cout << "Array 1\t\tArray2\n";
  for (int i = 0; i < kSize; ++i)
    cout << arr[i] << "\t\t" << arr2[i] << endl;

  return 0;
}
