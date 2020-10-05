/* Copyright 2018 */

#include <cstddef>
// using size_t
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

#include "../hw7/stat_tracker.h"
using csce240::StatTracker;


const int kInt_elems[] = {1, 2, 1, 5, 7, 2, 9};
const size_t kInt_elem_count = 7;
const int kInt_elem_mean = 3;  // actually 27/7
const int kInt_elem_median = 2;
const int kInt_elem_mode[] = {1, 2};


/* Calculates the actual mean, prints the expected and actual values, and
 *   returns whether they are the same.
 */
template <class T>
bool TestMean(const StatTracker<T>& tracker, const T& expected) {
  T actual = tracker.Mean();
  cout << "Expected mean: " << expected
      << ", Actual mean: " << actual << endl;
  return actual == expected;
}


/* Calculates the actual median, prints the expected and actual values, and
 *   returns whether they are the same.
 */
template <class T>
bool TestMedian(const StatTracker<T>& tracker, const T& expected) {
  T actual = tracker.Median();
  cout << "Expected median: " << expected
      << ", Actual median: " << actual << endl;
  return actual == expected;
}


/* Calculates the actual mode, prints the expected and actual values, and
 *   returns whether they are the same.
 */
template <class T>
bool TestMode(const StatTracker<T>& tracker, const vector<T>& expected) {
  vector<T> actual = tracker.Mode();
  cout << "Expected mode: ";
  typename std::vector<T>::iterator it;
  typename std::vector<T>::iterator e_it;
  typename std::vector<T>::iterator a_it;

  for (it = expected.begin(); it != expected.end(); ++it){
    cout << *it;
    if (it + 1 != expected.end())
      cout << ' ';
  }
  cout << "Actual Mode: ";
  for (it = actual.begin(); it != actual.end(); ++it){
    cout << *it;
    if (it + 1 != actual.end())
      cout << ' ';
  }

  if (expected.size() != actual.size())
    return false;

  for (e_it = expected.begin(), a_it = actual.begin();
    e_it != expected.end() && a_it != actual.end();
    ++e_it, ++a_it)
    if (*e_it != *a_it)
      return false;

  return true;
}
template <class T>
StatTracker<int> TestAdd(vector<int>& el) {
  typename std::vector<T>::iterator it;
  StatTracker<int> tracker;
  for (it = el.begin(); it != el.end(); ++it)
    tracker.Add(*it);
  return tracker;
}

void TestIntStats() {
  vector<int> elems;
  elems.assign(kInt_elems, kInt_elems + kInt_elem_count);

//  typename std::vector<T>::iterator it;
//  StatTracker<int> tracker;

//  for (it = elems.begin(); it != elems.end(); ++it)
//    tracker.Add(*it);

  StatTracker<int> tester;
  tester.Add(2);
  tester.Add(3);

//  cout << tester << endl;
  // cout << tester.v.at(1) << " " << tester.v.at(2);

  StatTracker<int> tracker(elems);
//  cout << tester.Extract << endl;

  if (!TestMean(tracker, kInt_elem_mean))
    cout << ": FAILED\n";
  else
    cout << ": PASSED\n";

  if (!TestMedian(tracker, kInt_elem_median))
    cout << ": FAILED\n";
  else
    cout << ": PASSED\n";

  tracker.Mode();
/*
  vector<int> expected_mode;
  expected_mode.assign(kInt_elem_mode, kInt_elem_mode + 2);
  if (!TestMode(tracker, expected_mode))
    cout << ": FAILED" << endl;
  else
    cout << ": PASSED" << endl;
*/
}

int main(int argc, char* argv[]) {
  TestIntStats();

  return 0;
}
