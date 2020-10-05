/* Copyright 2018 
 * Separate this file into a header and source file to fix scope problem.
 */
#include <iostream>
using std::cout;
using std::endl;

/* A void function which displays Hello, World named HelloWorld01
 */
void HelloWorld01(void) {
  cout << "Hello, World" << endl;
}

int main(int argc, char* argv[]) {
  // call HelloWorld01
  HelloWorld01();

  // call HelloWorld02
  HelloWorld02();

  return 0;
}

/* A void function which displays Hello, World named HelloWorld02
 */
void HelloWorld02(void) {
  cout << "Hello, World" << endl;
}

