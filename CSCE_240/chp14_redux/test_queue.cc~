/* Copyright 2018 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <list>
using std::list;

#include "../chp11_2/queue.h"
using csce240::IntQueue;


void PrintQueue(IntQueue* queue) {
  while (!queue->Empty()) {
    cout << queue->Pop() << ' ';
  }
  cout << endl;
}

void PrintList(const list<int>& list) {
}

void FillList(list<int>* list, unsigned int size) {
  for (unsigned int i = 1; i < size+1; ++i) {
    list->push_back(i);
  }
}

int main(int argc, char* argv[]) {
  list<int> int_list;

  FillList(&int_list, 10);
  IntQueue int_queue(int_list);

  cout << "Testing IntQueue:" << endl;
  PrintQueue(&int_queue);

  return 0;
}
