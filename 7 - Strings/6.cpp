// Reverse all the words in a sentence.

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

using std::reverse;
using std::string;

string ReverseWords(string *s) {
  // Reverses the whole string first.
  reverse(s->begin(), s->end());

  size_t start = 0, end;
  while ((end = s->find(" ", start)) != string::npos) {
    // Reverses each word in the string.
    reverse(s->begin() + start, s->begin() + end);
    start = end + 1;
  }
  // Reverses the last word.
  reverse(s->begin() + start, s->end());
  return *s;
}

int main() {
  string s = "Alice likes Bob";
  std::cout << ReverseWords(&s) << '\n';
}