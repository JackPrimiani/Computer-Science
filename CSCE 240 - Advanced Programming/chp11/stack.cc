/* Copyright 2018 */

#include "stack.h"  // NOLINT

namespace csce240 {

IntStack::IntStack(const std::vector<int>& store) {
  for (std::size_t i = 0; i < store.size(); ++i) {
    Push(store.at(i));
  }
}

void IntStack::Push(int value) {
  push_back(value);
}

int IntStack::Pop() {
  int tmp = back();
  pop_back();
  return tmp;
}

int IntStack::Top() const {
  return back();
}

bool IntStack::Empty() const {
  return 0 == size();
}

}  // namespace csce240
