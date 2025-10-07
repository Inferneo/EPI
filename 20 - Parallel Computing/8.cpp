// Implement a Timer Class

#include <chrono>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <unordered_map>

using namespace std;

class Timer {
public:
  using Clock = chrono::steady_clock;
  using TimePoint = chrono::time_point<Clock>;

  Timer() : stop_flag(false) {
    dispatcher = thread(&Timer::dispatch_loop, this);
  }

  ~Timer() {
    {
      unique_lock<mutex> lock(mtx);
      stop_flag = true;
      cv.notify_all();
    }
    dispatcher.join();
  }

  void start(const string &name, chrono::milliseconds delay,
             function<void()> func) {
    TimePoint run_time = Clock::now() + delay;
    {
      unique_lock<mutex> lock(mtx);
      if (tasks.count(name))
        return; // already scheduled
      tasks[name] = {run_time, func};
      pq.push({run_time, name});
      cv.notify_all();
    }
  }

  void cancel(const string &name) {
    unique_lock<mutex> lock(mtx);
    tasks.erase(name); // lazy delete (won't run when popped)
    cv.notify_all();
  }

private:
  struct Task {
    TimePoint time;
    string name;
    bool operator>(const Task &other) const { return time > other.time; }
  };

  thread dispatcher;
  mutex mtx;
  condition_variable cv;
  bool stop_flag;

  priority_queue<Task, vector<Task>, greater<Task>> pq;
  unordered_map<string, pair<TimePoint, function<void()>>> tasks;

  void dispatch_loop() {
    while (true) {
      unique_lock<mutex> lock(mtx);

      if (stop_flag)
        break;

      if (pq.empty()) {
        cv.wait(lock);
        continue;
      }

      auto next = pq.top();
      auto now = Clock::now();

      if (next.time > now) {
        cv.wait_until(lock, next.time);
        continue;
      }

      pq.pop();

      if (!tasks.count(next.name))
        continue; // cancelled
      auto func = tasks[next.name].second;
      tasks.erase(next.name);

      lock.unlock();
      func();
    }
  }
};

int main() {
  Timer t;
  t.start("task1", chrono::seconds(2), []() { cout << "task1 executed\n"; });
  this_thread::sleep_for(chrono::seconds(1));
  t.cancel("task1");
  t.start("task2", chrono::seconds(1), []() { cout << "task2 executed\n"; });
  this_thread::sleep_for(chrono::seconds(3));
}
