#include <bitset>
#include <iostream>

using std::bitset;
using std::cout;

int main() {

  int x = 0b11100;

  int out = x & (x - 1);
//   int out = x >> 3;

  cout << bitset<8>(x) << '\n';
  cout << bitset<8>(out) << '\n';
}