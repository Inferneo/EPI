// Add Two Strings of Binary Numbers

#include <algorithm>
#include <iostream>
#include <string>

using std::cout;
using std::reverse;
using std::string;

string AddBinStrings(const string &b1, const string &b2) {
  string b_sum;
  int sum = 0, carry = 0;
  int i = b1.size() - 1, j = b2.size() - 1;

  while (i >= 0 || j >= 0 || carry) {
    sum = carry;
    if (i >= 0) {
      sum += b1[i--] - '0';
    }
    if (j >= 0) {
      sum += b2[j--] - '0';
    }
    b_sum.push_back(char(sum % 2 + '0'));
    carry = sum / 2;
  }
  reverse(b_sum.begin(), b_sum.end());
  return b_sum;
}

int main() {
    string b1 = "1010101";
    string b2 = "1000101";
    auto s = AddBinStrings(b1, b2);
    cout << s << '\n';
}