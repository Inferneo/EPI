// Count the Number of Set Bits

#include <bitset>
#include <iostream>

using std::bitset;

short CountBits(unsigned int x) {
  short count = 0;
  while (x) {
    count += x & 1;
    x >>= 1;
  }
  return count;
}

int main() {
    int x = 0b11011111;
    std::cout << bitset<8>(x) << '\t' << CountBits(x) << '\n';
}

