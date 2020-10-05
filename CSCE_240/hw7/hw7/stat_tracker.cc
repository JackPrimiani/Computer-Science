/*
Copyright 2018
Author: Jack Primiani
December 8, 2018
*/

#include "stat_tracker.h"  // NOLINT

namespace csce240 {

template <class T>
StatTracker<T>::StatTracker(const std::vector<T>& vec) {
  for (std::size_t i = 0;  i < vec.size(); ++i) {
    Add(vec.at(i));
  }
  S = Count();
}

template <class T>
T StatTracker<T>::operator+(const T x) const {
  return this + x;
// (static_cast<double>x)+(static_cast<double>y);
}

template <class T>
T StatTracker<T>::operator/(const T x) const {
  return this / x;
}

template <class T>
bool StatTracker<T>::operator<(const T x) const {
  return this < x;
}

template <class T>
bool StatTracker<T>::operator==(const T x) const {
  return !(this < x || x < this);
}

template <class T>
void StatTracker<T>::Add(T val) {
  v.std::vector<T>::push_back(val);
  S = Count();
}

template <class T>
size_t StatTracker<T>::Count() {
  return v.size();
}

template <class T>
std::ostream& StatTracker<T>::Extract(std::ostream& out) const {
  typename std::vector<T>::const_iterator c_it;
  std::size_t count = 0;
  for (c_it = v.begin(); c_it != v.end(); ++c_it) {
    out << *c_it;
    if (count + 1 < std::vector<T>::size()) {
      out << ", ";
      ++count;
    }
  }
  return out;
}

template <class T>
const T StatTracker<T>::Mean() const {
  T av = 0;
  T siz = v.size();
  for (size_t i = 0; i < S; ++i) {
    av = av + v.at(i);
  }
  av = av/siz;
  return av;
}
// T = T + T and T = T / int must be defined

template <class T>
const T StatTracker<T>::Median() const {
  T temp, med = 0;
  size_t x;
  std::vector<T> vec;
  for (size_t i = 0; i < S; ++i) {
    vec.std::vector<T>::push_back(v.at(i));
  }
  for (size_t j = 0; j < vec.size(); ++j) {
    for (size_t k = j + 1; k < vec.size() - 1; ++k) {
      if (vec[k] < vec[j]) {
        temp = vec[j];
        vec[j] = vec[k];
        vec[k] = temp;
      }
    }
  }

  x = vec.size() / 2;
  if (x%2 == 1) {
    med = vec[x];
  } else {
    med = (vec[x - 1] + vec[x]) / 2;
  }
  return med;
}
// T = T / int must be defined
template <class T>
const std::vector<T> StatTracker<T>::Mode() const {
  T temp = 0;
  T bcount = 0, count = 1;
  std::vector<T> vec, mod;
  for (size_t i = 0; i < S; ++i) {
    vec.std::vector<T>::push_back(v.at(i));
  }
  for (size_t j = 0; j < vec.size(); ++j) {
    for (size_t k = j + 1; k < vec.size()-1; ++k) {
      if (vec[k] < vec[j]) {
        temp = vec[j];
        vec[j] = vec[k];
        vec[k] = temp;
      }
    }
  }
  for (size_t l = 0; l < S; ++l) {
    while (vec[l] == vec[l+1]) {
      count++;
      ++l;
    }
    if (bcount < count) {
      bcount = count;
    }
    count = 1;
  }
  for (size_t m = 0; m < S; ++m) {
    while (vec[m] == vec[m+1]) {
      count++;
      ++m;
    }
    if (count >= bcount) {
      mod.std::vector<T>::push_back(vec[m]);
    }
    count = 1;
  }
  return mod;
}
// T == T and T < T must be defined
}  // namespace csce240
