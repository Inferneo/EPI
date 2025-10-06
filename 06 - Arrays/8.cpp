// Enumerate All Primes to N

#include <cmath>
#include <deque>
#include <vector>

using std::deque;
using std::floor;
using std::vector;

// Given n, return all primes up to and including n.
vector<int> GeneratePrimes(int n) {
  vector<int> primes;
  // is_prime[p] represents if p is prime or not. Initially, set each to true,
  // excepting 0 and 1. Then use sieving to eliminate non-primes.
  deque<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int p = 2; p < n; ++p) {
    if (is_prime[p]) {
      primes.emplace_back(p);
      // Sieve p's multiples.
      for (int j = p; j <= n; j += p) {
        is_prime[j] = false;
      }
    }
  }
  return primes;
}

vector<int> GeneratePrimes_Optimized(int n) {
  const int size = floor(0.5 * (n - 3)) + 1;
  vector<int> primes;
  primes.emplace_back(2);
  // is_prime[i] represents whether (2i + 3) is prime or not. Initially, set
  // each to true. Then use sieving to eliminate nonprimes.
  deque<bool> is_prime(size, true);
  for (int i = 0; i < size; ++i) {
    if (is_prime[i]) {
      int p = (i * 2) + 3;
      primes.emplace_back(p);
      // Sieving from p^2, whose value is (4i^2 + 12i + 9). The index in
      // is_prime is (2i^2 + 6i + 3) because is_prime[i] represents 2i + 3.
      //
      // Note that we need to use long for j because p^2 might overflow.
      for (long j =
               ((static_cast<long>(i) * static_cast<long>(i)) * 2) + 6 * i + 3;
           j < size; j += p) {
        is_prime[j] = false;
      }
    }
  }
  return primes;
}
