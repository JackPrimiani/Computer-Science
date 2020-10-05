/* Copyright 2018 
This app accepts a non-case sensitive month name and prints the number of days
in that month followed by a new line. Returns 0.

When month is not found, returns 1.
*/

#include <algorithm>
using std::transform;
#include <cassert>
// using assert
#include <cctype>
// using toupper
#include <iostream>
using std::cout;
using std::endl;
#include <map>
using std::map;
#include <string>
using std::string;
#include <utility>
using std::make_pair;


/* Searches an array for a value and returns its index or -1 */
int LinearSearch(const string& key, const string vals[], const size_t size);

/* Transforms strings to all upper case */
void StrToUpper(string* source);

int main(int argc, char* argv[]) {
  assert(1 < argc);

  const int julian_size = 12;
  const string months[julian_size] = {
      "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST",
      "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
  const int days_in_month[julian_size] = {
      31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  const int month_index = 1;
  string month(argv[month_index]);
  StrToUpper(&month);

  int index = LinearSearch(month, months, julian_size);
  if (-1 < index)
    cout << months[index] << endl;
  else
    return -1;

  return 0;
}
