#include <functional>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::function;
using std::istringstream;
using std::priority_queue;
using std::string;
using std::vector;

vector<string> TopK(int k, istringstream &stream) {
  priority_queue<string, vector<string>, function<bool(string, string)>>
      min_heap([](const string &a, const string &b) {
        return a.size() >= b.size();
      });
  string next_string;

  while (stream >> next_string) {
    min_heap.emplace(next_string);
    if (min_heap.size() > k) {
      // Remove the shortest string. The comparison function above will order
      // the strings by length.
      min_heap.pop();
    }
  }
  vector<string> result;
  while (!min_heap.empty()) {
    result.emplace_back(min_heap.top());
    min_heap.pop();
  }
  return result;
}

int main() {
  istringstream is{"the man who jumped over the canoe"};
  int top = 2;
  auto large_strings = TopK(top, is);
  for (auto s : large_strings) {
    cout << s << '\n';
  }
}
