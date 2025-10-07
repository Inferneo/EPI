// Reverse Bits

#include <cmath>
#include <vector>

using std::pow;
using std::vector;

long ReverseBits(long x) {
  const int kWordSize = 16;
  const int kBitMask = 0xFFFF;
  vector<long> precomputed_reverse(pow(2, kWordSize));
  return precomputed_reverse[x & kBitMask] << (3 * kWordSize) |
         precomputed_reverse[(x >> kWordSize) & kBitMask] << (2 * kWordSize) |
         precomputed_reverse[(x >> (2 * kWordSize)) & kBitMask] << kWordSize |
         precomputed_reverse[(x >> (3 * kWordSize)) & kBitMask];
}
