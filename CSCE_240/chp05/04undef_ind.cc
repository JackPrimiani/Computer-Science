/*
 * Copyright 2018
 * Created by Jeremy S Lewis
 */

#include <iostream>
using std::cout;
using std::endl;

#include <array>
using std::array;


int main(int argc, char** argv) {
  // create double array from initializer list of 4 floating point literals
  array<double, 4> dbl_arr = {1.17, 2.68, 3.14, 4.90};
  unsigned int kStart = 0, kEnd = 3;

  // tab and display elements from positions -1 to 4, by 1 using []
  for (int i = kStart; static_cast<unsigned int>(i) < kEnd; ++i)
    cout << dbl_arr.at(i) << endl;

  // create a double array class instance with size 4, reuse literals

  // tab and display elements from positions -1 to 4, by 1 using []

  // tab and display elements from positions -1 to 4, by 1 using array::at

  return 0;
}
