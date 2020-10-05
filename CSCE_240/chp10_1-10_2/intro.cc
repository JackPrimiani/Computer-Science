/* Copyright 2018
 * 
 * Introduction to pointers
 */

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  for(int i = 0; i < argc; i++){
    cout << " i: " << argv[i] << endl;
  }
  // demonstrate decl and assignment of double pointers to automatic vars
  double a=0.0, b=0.5, c=1.0
  double *x, *y, *z;

  // introduce and demonstrate address of-operator
  x= &a;
  cout << "a is " << a << endl; 

  // introduce and deomonstrate the derefence operator

  cout << "x is " << *x << endl;
  *x += 1.8;
  x = &b; 
  *x += 1.8;
  x = &c; 
  *x +=1.8;
  cout << "a is " << a << endl;
  // demonstrate creation of dynamic variable

  // examine the behavior of assignment operator between pointers

  // demonstrate returning memory to freestore/heap


  return 0;
}
