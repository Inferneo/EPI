// Compute the spreadsheet column encoding

#include <iostream>
#include <string>

int SSDecodeColID(const std::string &col) {
  int result = 0;

  for (char c : col) {
    result = result * 26 + c - 'A' + 1;
  }

  return result;
}

std::string IntToColID(int id) {

  std::string s;
  while (id) {
    --id;
    s += id % 26 + 'A';
    id /= 26;
  }
  return {s.rbegin(), s.rend()};
}

int main() {
  std::cout << SSDecodeColID("ZZ") << '\n';
  std::cout << IntToColID(1) << '\n';
}