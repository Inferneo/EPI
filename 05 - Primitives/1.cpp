// Computing the Parity of a Word

#include <iostream>

using std::cout;

short Parity(unsigned long x) {
  short result = 0;
  while (x) {
    result ^= 1;
    x &= (x - 1); // x &= (x-1) drops the lowest set bit, x &= ~(x-1) isolates
                  // the lowest set bit.
  }
  return result;
}

short Parity_Associativity(unsigned long x) {
  x ^= x >> 32;
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  return x & 0x1;
}

int main() {
  short p = Parity(0b1111);
  cout << p << '\n';
}

// short Parity (unsigned long x) {
//     const int kWordSize = 16;
//     const int kBitMask = 0xFFFF;
//     return precomputed_parity[x >> (3 * kWordSize)] ^
// }
