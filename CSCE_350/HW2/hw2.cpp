/*
Jack Primiani
October 14, 2019
CSCE 350
*/

/*
This is not exhaustive search.
I was unable to create my own solution for this problem with exaustive search, however I found a this website to help implement another method that solves this puzzle:
https://www.geeksforgeeks.org/solving-cryptarithmetic-puzzles-backtracking-8/
*/

#include <iostream>
#include<vector>
using namespace std;
vector<int> use(10); 

struct node{
  char character;
  int value;
};

int isValid(node* nodeList, const int count, string s1, string s2, string s3){
  int val1 = 0, val2 = 0, val3 = 0, m = 1, j, i;
//find value for first string
  for (i = s1.length() - 1; i >= 0; i--){ 
    char ch = s1[i];
    for (j = 0; j < count; j++)
      if (nodeList[j].character == ch)
      break;
    val1 += m * nodeList[j].value;
    m *= 10;
  }
  m = 1;
//find value for second string
  for (i = s2.length() - 1; i >= 0; i--){ 
    char ch = s2[i];
    for (j = 0; j < count; j++)
      if (nodeList[j].character == ch)
      break;
    val2 += m * nodeList[j].value;
    m *= 10;
  }
  m = 1;
//find value for third string
  for (i = s3.length() - 1; i >= 0; i--){
    char ch = s3[i];
    for (j = 0; j < count; j++)
      if (nodeList[j].character == ch)
      break;
    val3 += m * nodeList[j].value;
    m *= 10;
  }
//assure that 3rd string is equal to the sum of the 1st and 2nd
  if (val3 == (val1 + val2)) 
    return 1;
  return 0;
}
bool permutation(int count, node* nodeList, int n, string s1, string s2, string s3){
  int x=0;
  if (n == count - 1){ 
    for (int i = 0; i < 10; i++){
      if (use[i] == 0){ 
        nodeList[n].value = i; //assign value i
        if (isValid(nodeList, count, s1, s2, s3) == 1){ 
          for(size_t j=0; j<s1.size(); j++){
            while(s1.at(j)!=nodeList[x].character){
              x++;
            }
            cout << nodeList[x].value;
            x=0;
          }
          cout << "+";
          for(size_t k=0; k<s2.size(); k++){
            while(s2.at(k)!=nodeList[x].character){
              x++;
            }
            cout << nodeList[x].value;
            x=0;
          }
          cout << "=";
          for(size_t l=0; l<s3.size(); l++){
            while(s3.at(l)!=nodeList[x].character){
              x++;
            }
            cout << nodeList[x].value;
            x=0;
          }
          cout << endl;
          return true;
        }
      }
    }
    return false;
  }
  for (int i = 0; i < 10; i++){
    if (use[i] == 0){ 
      nodeList[n].value = i; 
      use[i] = 1;
      if (permutation(count, nodeList, n + 1, s1, s2, s3))
        return true;
      use[i] = 0;
    }
  }
  return false;
}
bool solvePuzzle(string s1, string s2,string s3){
//Count of chars in which they have a single iteration
  int single = 0; 
  int len1 = s1.length();
  int len2 = s2.length();
  int len3 = s3.length();
//To delgate count of each character
  vector<int> count(26); 
  for (int i = 0; i < len1; i++)
    ++count[s1[i] - 'A'];
  for (int i = 0; i < len2; i++)
    ++count[s2[i] - 'A'];
  for (int i = 0; i < len3; i++)
    ++count[s3[i] - 'A'];
  for (int i = 0; i < 26; i++)
    if (count[i] > 0)
    single++;
  if (single > 10){ 
    cout << "Invalid strings";
    return 0;
  }
  node nodeList[single];
  for (int i = 0, j = 0; i < 26; i++){ 
    if (count[i] > 0){
      nodeList[j].character = char(i + 'A');
      j++;
    }
  }
  return permutation(single, nodeList, 0, s1, s2, s3);
}

int main (int argc, char **argv) {
   string puzzle;
   cout << "Enter Cryptarithmetic Puzzle(Uppercase Only)" << endl;
   cin >> puzzle;
   string s1 = puzzle.substr(0, puzzle.find("+"));
   string s2 = puzzle.substr(puzzle.find("+")+1, (puzzle.find("=")-1)-puzzle.find("+"));
   string s3 = puzzle.substr(puzzle.find("=")+1, puzzle.size()-1);

   if (solvePuzzle(s1, s2, s3) == false){
      cout << "No solution" << endl;
   }
}
