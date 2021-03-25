/* Copyright 2018 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <list>
using std::list;

#include "../chp14/ppt.h"
#include "../chp14/queue.h"
using namespace csce240;


void FillList(list<int>* list, unsigned int size) {
  for (unsigned int i = 1; i < size+1; ++i) {
    list->push_back(i);
  }
}

int main(int argc, char* argv[]) {
  list<int> int_list;
  FillList(&int_list, 10);
  PPT *ppt = new IntQueue(int_list);

  cout << *ppt << endl;

  return 0;
}
