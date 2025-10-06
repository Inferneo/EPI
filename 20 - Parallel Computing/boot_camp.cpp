// Semaphore

#include <condition_variable>
#include <mutex>

using std::condition_variable;
using std::lock_guard;
using std::mutex;
using std::unique_lock;

class Semaphore {
public:
  Semaphore(int max_available) : max_available_(max_available), taken_(0) {};

  void Acquire() {
    unique_lock<mutex> lock(mx_);
    while (taken_ == max_available_) {
      cond_.wait(lock);
    }
    ++taken_;
  }

  void Release() {
    lock_guard<mutex> lock(mx_);
    --taken_;
    cond_.notify_all();
  }

private:
  int max_available_;
  int taken_;
  mutex mx_;
  condition_variable cond_;
};