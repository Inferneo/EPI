// Buy and Sell a Stock Twice

#include <limits>
#include <vector>

using std::max;
using std::min;
using std::vector;

double BuyAndSellStockTwice(const vector<double> &prices) {
  double max_total_profit = 0;
  vector<double> first_buy_sell_profits(prices.size(), 0);
  double min_price_so_far = std::numeric_limits<double>::max();

  // Forward phase. For each day, we record maximum profit if we sell on that
  // day.
  for (int i = 0; i < prices.size(); ++i) {
    min_price_so_far = min(prices[i], min_price_so_far);
    max_total_profit = max(max_total_profit, prices[i] - min_price_so_far);
    first_buy_sell_profits[i] = max_total_profit;
  }

  // Backward phase. For each day, find the maximum profit if we make the second
  // buy on that day.
  double max_price_so_far = std::numeric_limits<double>::min();
  for (int i = prices.size() - 1; i >= 0; --i) {
    max_price_so_far = max(max_price_so_far, prices[i]);
    max_total_profit = max(max_total_profit, max_price_so_far - prices[i] +
                                                 first_buy_sell_profits[i - 1]);
  }

  return max_total_profit;
}