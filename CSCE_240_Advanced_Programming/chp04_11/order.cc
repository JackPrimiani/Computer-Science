/* Copyright 2018
 *
 * Separate functions into declaration and definition to fix scope issue.
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
  // TODO: Fix the scope problem
  HelloWorld02();

  return 0;
}

/* A void function which displays Hello, World named HelloWorld02
 */
void HelloWorld02(void) {
  cout << "Hello, World" << endl;
}
