// Compute the k Closest Stars

#include <array>
#include <cmath>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using std::array;
using std::cout;
using std::getline;
using std::istringstream;
using std::priority_queue;
using std::sqrt;
using std::stod;
using std::string;
using std::stringstream;
using std::vector;

struct Star {
  bool operator<(const Star &that) const {
    return this->Distance() < that.Distance();
  }

  double Distance() const { return sqrt(x * x + y * y + z * z); }

  double x, y, z;
};

vector<Star> kClosestStars(int k, istringstream &stars) {
  // max_heap to store the k closest stars seen so far.

  priority_queue<Star, vector<Star>> max_heap;

  string line;
  while (getline(stars, line)) {
    stringstream line_stream(line);
    array<double, 3> data; // stores x, y and z.
    for (int i = 0; i < 3; ++i) {
      string buf;
      getline(line_stream, buf, ' ');
      data[i] = stod(buf);
    }

    // Add each star to the max_heap. If the max_heap exceeds k, remove the
    // maximum element from the max_heap.
    max_heap.emplace(Star{data[0], data[1], data[2]});
    if (max_heap.size() == k + 1) {
      max_heap.pop();
    }
  }

  // Iteratively extract from the max_heap, which yields the stars sorted
  // according from furthest to closest.
  vector<Star> closest_stars;
  while (!max_heap.empty()) {
    closest_stars.emplace_back(max_heap.top());
    max_heap.pop();
  }
  return {closest_stars.rbegin(), closest_stars.rend()};
}

int main() {
  int k = 2;
  istringstream stars{
      R"(2 3 4
5 50 60
8 11 20
30 3 1
54 2 65)"};

  auto close = kClosestStars(k, stars);

  for (auto x : close) {
    array<double, 3> star = {x.x, x.y, x.z};
    cout << '{' << star[0] << ',' << star[1] << ',' << star[2] << '}' << '\n';
  }
}