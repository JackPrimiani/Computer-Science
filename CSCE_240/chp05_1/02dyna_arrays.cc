/*
 * Copyright 2018
 * Created by Jeremy S Lewis
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
/*
argument: char*
declaration: int *dyna_arr
*/
int main(int argc, char* argv[]) {
  // create an int pointer to hold a dynamic array
  int *dyna_arr; 

  // prompt user for the size of the array
  cout << "Enter array size: "
  int size;
  cin >> size;
  
  // request memory for an array of given size
  dyna_arr = new int[size]; 
  // fill array with integers from 1 to size - 1
  for (int i = 0; i < size; i++)
    dyna_arr[i] = i + 1;
  
  // double array, while retaining the original values

  int *tmp = new int[2*size];
  for (int i = 0; i < size; i++)
    tmp[i] = dyna_arr[i];
  delete []dyna_arr;
  dyna_arr = tmp;
  // half array while retaining the original size / 2 values


  delete []dyna_arr;  // every "new" needs a delete

  return 0;
}
