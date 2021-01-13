/* Copyright 2018 */

#ifndef _LECT_CHP11_2_QUEUE_H_  //NOLINT
#define _LECT_CHP11_2_QUEUE_H_  //NOLINT

#include <list>

#include "../chp11_2/ppt.h"

// introduce namespace csce240
namespace csce240 {

class IntQueue : std::list<int>, public PPT {
 public:
  inline IntQueue() {}
  explicit IntQueue(const std::list<int>&);

  void Push(int val);

  int Pop();

  int Top() const;

  bool Empty() const;
};

}  // namespace csce240

#endif  //NOLINT
