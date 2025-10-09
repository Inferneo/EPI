// Find the Smallest Subarray Covering All Values

#include "bits/stdc++.h"
#include <list>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Subarray {
  int start, end;
};

Subarray
FindSmallestSubarrayCoveringSet(const vector<string> &paragraph,
                                const unordered_set<string> &keywords) {
  unordered_map<string, int> keywords_to_cover;
  for (auto keyword : keywords) {
    ++keywords_to_cover[keyword];
  }
  Subarray result{-1, -1};
  int remaining_to_cover = keywords.size();
  for (int left = 0, right = 0; right < paragraph.size(); ++right) {
    if (keywords.count(paragraph[right]) &&
        --keywords_to_cover[paragraph[right]] >= 0) {
      --remaining_to_cover;
    }

    // Keeps advancing left until keywords_to_cover does not contain all
    // keywords.
    while (remaining_to_cover == 0) {
      if ((result.start == -1 && result.end == -1) ||
          right - left < result.end - result.start) {
        result = {left, right};
      }
      if (keywords.count(paragraph[left]) &&
          ++keywords_to_cover[paragraph[left]] > 0) {
        ++remaining_to_cover;
      }
      ++left;
    }
  }
  return result;
}

// O(n) complexity, each of the two indices is advanced at most n - 1 times.

Subarray
FindSmallestSubarrayCoveringSubset(istringstream *sin,
                                   const vector<string> &query_strings) {
  // Tracks the last occurrence (index) of each string in query_strings.
  list<int> loc;
  unordered_map<string, list<int>::iterator> dict;
  for (auto s : query_strings) {
    dict.emplace(s, loc.end());
  }

  Subarray res = Subarray{-1, -1};
  int idx = 0;
  string s;
  while (*sin >> s) {
    auto it = dict.find(s);
    if (it != dict.end()) { // s is in query_strings.
      if (it->second != loc.end()) {
        // Explicitly remove s so that when we add it, it's the string most
        // recently added to loc.
        loc.erase(it->second);
      }
      loc.emplace_back(idx);
      it->second = --loc.end();
    }

    if (loc.size() == query_strings.size()) {
      // We have seen all strings in query_string, let's get to work.
      if ((res.start == -1 && res.end == -1) ||
          idx - loc.front() < res.end - res.start) {
        res = {loc.front(), idx};
      }
    }
    ++idx;
  }
  return res;
}

// Complexity still O(n)