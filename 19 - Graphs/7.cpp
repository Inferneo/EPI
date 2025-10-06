// Transform One String To Another

#include <queue>
#include <string>
#include <unordered_set>

using std::queue;
using std::string;
using std::unordered_set;

// Uses BFS to find the least steps of transformation.
int TransformString(unordered_set<string> D, const string &s, const string &t) {
  struct StringWithDistance {
    string candidate_string;
    int distance;
  };

  queue<StringWithDistance> q;
  D.erase(s); // Marks s as visited by erasing it in D.
  q.emplace(StringWithDistance{s, 0});

  while (!q.empty()) {
    StringWithDistance f(q.front());
    // Returns if we find a match.
    if (f.candidate_string == t) {
      return f.distance; // Number of steps reaches t.
    }
    // Tries all possible transformations of f.candidate_string.
    string str = f.candidate_string;
    for (int i = 0; i < str.size(); ++i) {
      for (int j = 0; j < 26; ++j) { // Iterates through 'a' ~ 'z'.
        str[i] = 'a' + j;
        auto it = D.find(str);
        if (it != D.end()) {
          D.erase(it);
          q.emplace(StringWithDistance{str, f.distance + 1});
        }
      }
      str[i] = f.candidate_string[i]; // Reverts the change of str.
    }
    q.pop();
  }

  return -1; // Cannot find a possible transformation.
}