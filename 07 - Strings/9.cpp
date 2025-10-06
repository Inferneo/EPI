// Convert from Roman to Decimal

#include "bits/stdc++.h"
using namespace std;

unordered_map<char, int> kMap = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                 {'C', 100}, {'D', 500}, {'M', 1000}};

int RomanToDecimal(const string &num) {
  int dec = kMap[num.back()];
  for (int i = num.length() - 2; i >= 0; --i) {
    if (kMap[num[i]] < kMap[num[i + 1]]) {
      dec -= kMap[num[i]];
    } else {
      dec += kMap[num[i]];
    }
  }
  return dec;
}

int main() { cout << RomanToDecimal("V") << endl; }