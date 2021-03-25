/* Copyright 2018 */

#ifndef _LECT_CHP11_2_QUEUE_H_  //NOLINT
#define _LECT_CHP11_2_QUEUE_H_  //NOLINT

#include <list>
#include <iostream>

#include "../chp14/ppt.h"

// introduce namespace csce240
namespace csce240 {

template <class T>
class Queue : protected std::list<T>, public PPT {
 public:
  inline Queue() {}
  explicit Queue(const std::list<T>&);

  void Push(T val);

  T Pop();

  T Top() const;

  bool Empty() const;

  std::ostream& Extract(std::ostream&) const;
};

}  // namespace csce240

#endif  //NOLINT
