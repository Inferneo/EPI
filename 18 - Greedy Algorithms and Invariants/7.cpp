// Compute the Maximum Water Trapped by a Pair of Vertical Lines

#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::vector;

int GetMaxTrappedWater(const vector<int> &heights) {
  int i = 0, j = heights.size() - 1, max_water = 0;
  while (i < j) {
    int width = j - i;
    max_water = max(max_water, width * min(heights[i], heights[j]));
    if (heights[i] > heights[j]) {
      --j;
    } else if (heights[i] < heights[j]) {
      ++i;
    } else { // heights[i] == heights[j]
      ++i, --j;
    }
  }
  return max_water;
}