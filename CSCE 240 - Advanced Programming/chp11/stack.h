/* Copyright 2018 */

#ifndef _LECT_CHP11_2_STACK_H_  //NOLINT
#define _LECT_CHP11_2_STACK_H_  //NOLINT

#include<vector>

#include "../chp11_2/ppt.h"

namespace csce240 {

class IntStack : std::vector<int>, public PPT {
 public:
  inline IntStack() {}
  explicit IntStack(const std::vector<int>&);

  void Push(int);

  int Pop();

  int Top() const;

  bool Empty() const;
};

}  // namespace csce240

#endif  //NOLINT
