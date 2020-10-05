/*
Copyright 2018
Author: Jack Primiani
December 08, 2018
*/
#ifndef HW7_STAT_TRACKER_H_  // NOLINT
#define HW7_STAT_TRACKER_H_  // NOLINT

#include <cstddef>
#include <ostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

namespace csce240 {

template <class T>
class StatTracker {
 public:
  std::vector<T> v;
  size_t S;

  inline StatTracker() {}
  explicit StatTracker(const std::vector<T>&);

  T operator+(const T) const;

  T operator/(const T) const;

  bool operator<(const T) const;

  bool operator==(const T) const;

  void Add(T val);

  size_t Count();

  std::ostream& Extract(std::ostream&) const;

  const T Mean() const;  // T = T + T and T = T / int must be defined

  const T Median() const;   // T = T / int must be defined

  const std::vector<T> Mode() const;
};

}  // namespace csce240

#include "stat_tracker.cc" //  NOLINT

#endif  // NOLINT
