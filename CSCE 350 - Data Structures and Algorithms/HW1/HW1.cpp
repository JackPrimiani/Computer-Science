/*
Jack Primiani
September 11, 2019
CSCE 350
*/

#include <iostream>
using namespace std;

int main (int argc, char **argv) { 
  int l, m, d, r, sum=100;
  while(sum!=0) {
    cin >> l >> m >> d >> r;
    sum = l + m + d + r;
    cout << sum << endl;
  }
}
