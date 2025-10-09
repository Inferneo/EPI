// Test a String Over "{, }, (, ), [, ]" for Well-Formedness

#include "bits/stdc++.h"

using namespace std;

bool IsWellFormed(const string &s) {
  stack<char> left_chars;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
      left_chars.emplace(s[i]);
    } else {
      if (left_chars.empty()) {
        return false; // Unmatched right char.
      }
      if ((s[i] == ')' && left_chars.top() != '(') ||
          (s[i] == '[' && left_chars.top() != ']') ||
          (s[i] == '{' && left_chars.top() != '}')) {
        return false; // Mismatched chars.
      }
      left_chars.pop();
    }
  }
  return left_chars.empty();
}

// Time complexity O(n) since for each character O(1) operations.