/* Copyright 2018
 * 
 * The nullptr pointer literal
 */

#include <iostream>
using std::cout;
using std::endl;

int Pow(int a, int b);
int Pow(const int* a, const int* b);

int main(int argc, char* argv[]) {
  int a=3, b=4;
  int *x=NULL, *y=NULL;

  // call and print result of pow(a, b), pow(a, NULL), and pow(x, y)

  // if x and y were allocted, return memory

  return 0;
}

int Pow(int a, int b) {
  int pow = 1;
  for (int i = 0; i < b; ++i) {
    pow *= a;
  }

  return pow;
}
int Pow(const int* a, const int* b) {
  int pow = 1;
  for (int i = 0; i < *b; ++i)
    pow *= *a;

  return pow;
}
