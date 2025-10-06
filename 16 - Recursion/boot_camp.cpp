#include <iostream>

using std::cout;

long long GCD(long long x, long long y) { return y == 0 ? x : GCD(y, x % y); }

int main() { cout << GCD(51, 34) << '\n'; }
