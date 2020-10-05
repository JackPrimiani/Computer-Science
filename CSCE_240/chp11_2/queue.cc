/* Copyright 2018 */

#include "queue.h"  //NOLINT

namespace csce240 {

IntQueue::IntQueue(const std::list<int>& store) {
  std::list<int>::const_iterator c_it;
  for (c_it = store.begin(); c_it != store.end(); ++c_it)
    Push(*c_it);
}

void IntQueue::Push(int val) {
  push_front(val);
}

int IntQueue::Pop() {
  int temp = back();
  pop_back();
  return temp;
}

int IntQueue::Top() const {
  return back();
}

bool IntQueue::Empty() const {
  return empty();
}

}  // namespace csce240

