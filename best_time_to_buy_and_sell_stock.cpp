class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() <= 1) {
      return 0;
    }

    int max_profit = 0;
    int min_price = prices[0];

    for (int i = 1; i < prices.size(); ++i) {
      int profit = prices[i] - min_price;

      if (profit < 0) {
        min_price = prices[i];
      }
      else if (profit > 0) {
        if (profit > max_profit) {
          max_profit = profit;
        }
      }
    }

    return max_profit;
  }
};