// Making Change

#include <array>
using std::array;

int ChangeMaking(int cents) {
  const array<int, 6> kCoins = {100, 50, 25, 10, 5, 1};
  int num_coins = 0;
  for (int i = 0; i < kCoins.size(); ++i) {
    num_coins += cents / kCoins[i];
    cents %= kCoins[i];
  }
  return num_coins;
}