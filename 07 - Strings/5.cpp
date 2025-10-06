// Test Palindromicity

#include <cctype>
#include <iostream>
#include <string>

using std::cout;
using std::isalnum;
using std::string;
using std::tolower;

bool IsPalindrome(const string &s) {
  // i moves forward, j moves backward.
  int i = 0, j = s.size() - 1;
  while (i < j) {
    // i and j both skip non-alphanumeric characters.
    while (!isalnum(s[i]) && i < j) {
      ++i;
    }
    while (!isalnum(s[j]) && i < j) {
      --j;
    }
    if (tolower(s[i++]) != tolower(s[j--])) {
      return false;
    }
  }
  return true;
}

int main() {
  cout << IsPalindrome("A man, a plan, a canal, Panama.") << '\n';
  cout << IsPalindrome("Ray a Ray") << '\n';
}