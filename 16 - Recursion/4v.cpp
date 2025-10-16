// Generate the Power Set Using Bit Arrays.

#include <cmath>
#include <vector>

using std::log2;
using std::vector;

vector<vector<int>> GeneratePowerSet(const vector<int> &input_set) {
  vector<vector<int>> power_set;
  for (int int_for_subset = 0; int_for_subset < (1 << input_set.size());
       ++int_for_subset) {
    int bit_array = int_for_subset;
    vector<int> subset;
    while (bit_array) {
      subset.emplace_back(input_set[log2(bit_array & ~(bit_array - 1))]);
      bit_array &= bit_array - 1;
    }
    power_set.emplace_back(subset);
  }
  return power_set;
}