// Count the Number of Ways to Traverse a 2D Array

#include <vector>

using std::vector;

int ComputeNumberofWaysToXY(int x, int y,
                            vector<vector<int>> *number_of_ways_ptr) {
  if (x == 0 && y == 0) {
    return 1;
  }

  vector<vector<int>> &number_of_ways = *number_of_ways_ptr;
  if (number_of_ways[x][y] == 0) {
    int ways_top =
        x == 0 ? 0 : ComputeNumberofWaysToXY(x - 1, y, number_of_ways_ptr);
    int ways_left =
        y == 0 ? 0 : ComputeNumberofWaysToXY(x, y - 1, number_of_ways_ptr);
    number_of_ways[x][y] = ways_top + ways_left;
  }
  return number_of_ways[x][y];
}

int NumberofWays(int n, int m) {
  vector<vector<int>> number_of_ways(n, vector<int>(m, 0));
  return ComputeNumberofWaysToXY(n - 1, m - 1, &number_of_ways);
}