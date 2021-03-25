/* Copyright 2018 */
#include <cassert>
// using assert
#include <cstdlib>
// using atoi
// using rand
// using srand
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include "../chp11_2/ppt.h"
using csce240::PPT;
#include "../chp11_2/queue.h"
using csce240::IntQueue;
#include "../chp11_2/stack.h"
using csce240::IntStack;

// anonymous namespace to name a global root for the search function
namespace {
  const int kRoot = 0;
}

inline int left_child(int root) {
  return 2*root + 1;
}
inline bool IsLeft(int child) {
  return child % 2 == 1;
}

inline int right_child(int root) {
  return 2*root + 2;
}
inline bool IsRight(int child) {
  return child % 2 == 0;
}

int Level(int index) {
  int level = 1;

  while (0 < index) {
    if (IsLeft(index))
      index -= 1;
    else
      index -= 2;

    index /= 2;
    ++level;
  }

  return level;
}

class Operation {
 public:
  virtual bool Operate(int, int) = 0;
};

class BinaryTreeSearch : public Operation {
 public:
  BinaryTreeSearch(int value) : value_(value), index_(-1) {}

  bool Operate(int index, int value) {
    if (value == value_) {
      index_ = index;
      return true;
    }
    else
      return false;
  }

 private:
  int value_;
  int index_;
};

class Printer : public Operation {
 public:
  Printer(int size) : size_(size) {}

  bool Operate(int index, int value) {
    if (index < size_) {
      cout << "tree[" << index << "]:" << value << endl;
      return false;
    }
    else
      return true;
  }

 private:
  int size_;
};

/* Visits each node in a tree either depth or breadth-first.
 *
 * tree: a binary tree stored in an array
 * t_size: number of elems in tree
 */
int Visit(const int* tree, const int t_size, PPT* Q, Operation* op) {
  assert(0 < t_size);

  Q->Push(kRoot);
  while (!Q->Empty()) {
    // get the next item from Q
    int root = Q->Pop();

    // if this is the value sought, return index
    if (op->Operate(root, tree[root]))
      return root;

    // when there is a left child, add to Q object
    if (left_child(root) < t_size)
      Q->Push(left_child(root));

    // when there is a right child, add to Q object
    if (right_child(root) < t_size)
      Q->Push(right_child(root));
  }

  // when Q is empty, value is not in tree
  return kRoot - 1;
}

int main(int argc, char* argv[]) {
  const int kValInd = 1;
  assert(1 < argc);
  int value = atoi(argv[kValInd]);

  const int tree[] = {
        0,   7,  11,  13, 17, 23, 29, 31, 37, 41, 43, 47, 51,
       57,  59,  61,  67, 71, 73, 79, 83, 87, 91, 93, 97, 99,
      101, 107, 111, 117
  };
  const int t_size = 30;

  IntStack stack;
  IntQueue queue;
  BinaryTreeSearch search(value);
  cout << "Index of " << value << ": " << Visit(tree, t_size, &stack, &search) << endl;
  Printer printer(t_size);
  Visit(tree, t_size, &stack, &printer);
  return 0;
}
