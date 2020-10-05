/* Copyright 2018 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <list>
using std::list;
#include <vector>
using std::vector;

#include "../chp14/ppt.h"
using csce240::PPT;
#include "../chp14/queue.cc"  //NOLINT
using csce240::Queue;
#include "../chp14/stack.h"
using csce240::IntStack;


void FillList(list<int>* list, unsigned int size) {
  for (unsigned int i = 1; i < size+1; ++i) {
    list->push_back(i);
  }
}

void FillVector(vector<int>* vector, unsigned int size) {
  for (unsigned int i = 1; i < size+1; ++i) {
    vector->push_back(i);
  }
}

int main(int argc, char* argv[]) {
  list<int> int_list;
  FillList(&int_list, 10);
  PPT *ppt = new Queue<int>(int_list);

  cout << *ppt << endl;

  delete ppt;

  vector<int> int_vector;
  FillVector(&int_vector, 10);
  ppt = new IntStack(int_vector);

  cout << *ppt << endl;
  delete ppt;

  return 0;
}
