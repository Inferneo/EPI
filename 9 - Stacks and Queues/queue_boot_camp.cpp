#include <algorithm>
#include <list>
#include <stdexcept>

using std::length_error;
using std::list;
using std::max_element;

class Queue {
public:
  void Enqueue(int x) { data_.emplace_back(x); }

  int Dequeue() {
    if (data_.empty()) {
      throw length_error("empty queue");
    }
    const int val = data_.front();
    data_.pop_front();
    return val;
  }

  int Max() const {
    if (data_.empty()) {
      throw length_error("cannot perform Max() on empty queue.");
    }
    return *max_element(data_.begin(), data_.end());
  }

private:
  list<int> data_;
};