// The GasUp Problem

#include <vector>

using std::size_t;
using std::vector;

const int kMPG = 20;

// gallons[i] is the amount of gas in city i, and distances[i] is the distance
// from city i to the next city.
size_t FindAmpleCity(const vector<int> &gallons, const vector<int> &distances) {
  int remaining_gallons = 0;
  struct CityAndRemainingGas {
    int city = 0, remaining_gallons = 0;
  };
  CityAndRemainingGas city_remaining_gallons_pair;
  const int num_cities = gallons.size();
  for (int i = 1; i < num_cities; ++i) {
    remaining_gallons += gallons[i - 1] - distances[i - 1] / kMPG;
    if (remaining_gallons < city_remaining_gallons_pair.remaining_gallons) {
        city_remaining_gallons_pair = {i, remaining_gallons};
    }
  }
  return city_remaining_gallons_pair.city;
}