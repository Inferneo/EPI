#include <iostream>
#include <string>
using std::string;

bool isPalindromic(const string &s) {
  auto b = s.begin();
  auto e = s.end() - 1;
  while (b <= e) {
    if (*b != *e) {
      return false;
    }
    ++b;
    --e;
  }
  return true;
}

int main() {
  string word = "hannah";
  std::cout << isPalindromic(word) << '\n';
}