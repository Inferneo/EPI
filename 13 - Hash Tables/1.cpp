// Test for Palindromic Permutations

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>

using std::begin;
using std::cout;
using std::end;
using std::none_of;
using std::string;
using std::unordered_map;

bool CanFormPalindrome(const string &s) {
  unordered_map<char, int> char_frequencies;
  // Compute the frequency of each char in s.
  for (char c : s) {
    ++char_frequencies[c];
  }

  // A string can be permuted as a palindrome if and only if the number of chars
  // whose frequency is odd at most 1.
  int odd_frequency_count = 0;
  return none_of(begin(char_frequencies), end(char_frequencies),
                 [&odd_frequency_count](const auto &p) {
                   return (p.second % 2) && ++odd_frequency_count > 1;
                 });
}

int main() { cout << CanFormPalindrome("killk") << '\n'; }