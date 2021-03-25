#include <cctype>
// using isdigit
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

int main(int argc, char* argv[]) {
  // Read a character string from stdin
  string word;
  cout << "Enter a word: ";
  cin >> word;

  // Determine whether the character string is a palindrome
  //     Consider both examining characters and
  bool is_pal = true;
  for (int i = 0, j = static_cast<int>(word.size()) - 1; i < j; ++i, --j) {
    if (word.at(i) != word[j]) {
      is_pal = false;
      break;
    }
  }
  cout << "Is";
  if (!is_pal)
    cout << " not";
  cout << " palindrome" << endl;

  //     building a new string
  string drow;
  for (int i = 0; i < static_cast<int>(word.size()); ++i)
    drow = word.at(i) + drow;

  cout << "Is";
  if (word != drow)
    cout << " not";
  cout << " palindrome" << endl;
  
  // Extact any digits and determine both sum of digits as well as digits read
  //     as base-10 integer. Try without isdigit or stoi
  int sum = 0;
  for (unsigned int i = 0; i < word.size(); ++i) {
    if ('0' <= word.at(i) && word.at(i) <= '9') {
      sum += (word.at(i) - '0');
    }
  }
  cout << "The sum of digits in " << word << " is " << sum << endl;
  
  return 0;
}
