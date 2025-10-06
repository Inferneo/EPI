#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using std::cout;
using std::greater;
using std::priority_queue;
using std::string;
using std::vector;

int main() {

  vector<int> nums = {10, 3, 45, 7, 22, 90, 1, 56};
  priority_queue<int, vector<int>, greater<int>> min_heap_int;
  for (auto x : nums) {
    min_heap_int.push(x);
    if (min_heap_int.size() > 3) {
      min_heap_int.pop();
    }
  }
  while (!min_heap_int.empty()) {
    cout << min_heap_int.top() << '\t';
    min_heap_int.pop();
  }
  cout << '\n';
}