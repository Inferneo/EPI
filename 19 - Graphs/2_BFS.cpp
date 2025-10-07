// Paint a Boolean Matrix

#include <array>
#include <deque>
#include <queue>
#include <vector>

using std::array;
using std::deque;
using std::queue;
using std::vector;

void FlipColor(int x, int y, vector<deque<bool>> *A_ptr) {
  vector<deque<bool>> &A = *A_ptr;
  const array<array<int, 2>, 4> kDirs = {{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};
  const bool color = A[x][y];

  struct Coordinate {
    int x, y;
  };
  queue<Coordinate> q;
  A[x][y] = !color; // Flips.
  q.emplace(Coordinate{x, y});
  while (!q.empty()) {
    Coordinate curr = q.front();
    for (auto dir : kDirs) {
      const int next_x = curr.x + dir[0], next_y = curr.y + dir[1];
      if (next_x >= 0 && next_x < A.size() && next_y >= 0 &&
          next_y < A[next_x].size() && A[next_x][next_y] == color) {
        // Flips the color.
        A[next_x][next_y] = !color;
        q.emplace(Coordinate{next_x, next_y});
      }
    }
    q.pop();
  }
}