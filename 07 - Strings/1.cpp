// Interconvert strings and integers

#include <iostream>
#include <string>

using std::cout;
using std::string;

string IntToString(int x) {
  bool is_negative = false;
  if (x < 0) {
    is_negative = true;
  }

  string s;
  if (x == 0) {
    s = "0";
  } else {
    while (x) {
      s += '0' + abs(x % 10);
      x /= 10;
    }
  }

  if (is_negative) {
    s += '-'; // Adds the negative sign back.
  }
  return {s.rbegin(), s.rend()};
}

int StringToInt(const string &s) {
  int result = 0;
  for (int i = s[0] == '-' ? 1 : 0; i < s.size(); ++i) {
    const int digit = s[i] - '0';
    result = result * 10 + digit;
  }
  return s[0] == '-' ? -result : result;
}

int main() {
  auto s = IntToString(-290);

  int o = StringToInt("750");

  cout << o << '\n';
  cout << s << '\n';
}
