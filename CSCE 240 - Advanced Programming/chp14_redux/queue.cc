/* Copyright 2018 */

#include "../chp14/queue.h"  //NOLINT

namespace csce240 {

template <class T>
Queue<T>::Queue(const std::list<T>& store) {
  typename std::list<T>::const_iterator c_it;
  for (c_it = store.begin(); c_it != store.end(); ++c_it)
    Push(*c_it);
}

template <class T>
void Queue<T>::Push(T val) {
  std::list<T>::push_front(val);
}

template <class T>
T Queue<T>::Pop() {
  T temp = std::list<T>::back();
  std::list<T>::pop_back();
  return temp;
}

template <class T>
T Queue<T>::Top() const {
  return std::list<T>::back();
}

template <class T>
bool Queue<T>::Empty() const {
  return std::list<T>::empty();
}

template <class T>
std::ostream& Queue<T>::Extract(std::ostream& out) const {
  typename std::list<T>::const_iterator c_it;
  std::size_t count = 0;
  for (c_it = std::list<T>::begin(); c_it != std::list<T>::end(); ++c_it) {
    out << *c_it;
    if (count + 1 < std::list<T>::size())
      out << ", ";
    ++count;
  }
  return out;
}

}  // namespace csce240

