// Compute the Fibonacci Numbers (Using Two Versions of Cache)

#include <iostream>
#include <unordered_map>

using std::cout;
using std::unordered_map;

unordered_map<int, int> cache;

int Fibonacci_DP(int n) {
  if (n <= 1) {
    return n;
  } else if (!cache.count(n)) {
    cache[n] = Fibonacci_DP(n - 1) + Fibonacci_DP(n - 2);
  }
  return cache[n];
}

int Fibonacci_It(int n) {
  if (n <= 1) {
    return n;
  }
  int f_minus_2 = 0, f_minus_1 = 1;
  for (int i = 2; i <= n; ++i) {
    int f = f_minus_2 + f_minus_1;
    f_minus_2 = f_minus_1;
    f_minus_1 = f;
  }
  return f_minus_1;
}

int main() {
  for (int i = 0; i < 10; ++i) {
    cout << Fibonacci_It(i) << '\n';
  }
}
