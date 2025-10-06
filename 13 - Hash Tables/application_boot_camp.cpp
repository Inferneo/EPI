#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::cout;
using std::sort;
using std::string;
using std::unordered_map;
using std::vector;

vector<vector<string>> FindAnagrams(const vector<string> &dictionary) {
  unordered_map<string, vector<string>> sorted_string_to_anagrams;
  for (const string &s : dictionary) {
    // Sorts the string, uses it as a key, and then appends the original string
    // back into the hash table as a value.
    string sorted_str(s);
    sort(sorted_str.begin(), sorted_str.end());
    sorted_string_to_anagrams[sorted_str].emplace_back(s);
  }

  vector<vector<string>> anagram_groups;
  for (const auto &p : sorted_string_to_anagrams) {
    if (p.second.size() >= 2) { // Found anagrams.
      anagram_groups.emplace_back(p.second);
    }
  }
  return anagram_groups;
}

int main() {
  vector<string> words = {"debitcard", "elvis",  "silent", "badcredit", "lives",
                          "freedom",   "listen", "levis",  "money"};
  auto anagrams = FindAnagrams(words);
  for (auto &x : anagrams) {
    for (auto &w : x) {
      cout << w << '\t';
    }
    cout << '\n';
  }
}