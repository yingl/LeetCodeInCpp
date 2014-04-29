class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() <= 1) {
      return 0;
    }

    int max_profit = 0;
    int max_profit_1 = 0;
    int max_profit_2 = 0;
    int size = prices.size();
    int min_price = prices[0];
    int max_price = prices[size - 1];
    vector<int> profits(size, 0);
    int i;

    for (i = 1; i < size; ++i) {
      int profit = prices[i] - min_price;

      if (profit < 0) {
        min_price = prices[i];
      }
      else {
        if (profit > max_profit_1) {
          max_profit_1 = profit;
        }
      }

      profits[i] = max_profit_1;
    }

    // 从后向前，搜索第2次交易的机会。这样可以利用第一次的成果！
    for (i = size - 2; i >= 0; --i) {
      int profit = max_price - prices[i];

      if (profit < 0) {
        max_price = prices[i];
      }
      else {
        if (profit > max_profit_2) {
          max_profit_2 = profit;
        }

        if ((max_profit_2 + profits[i]) > max_profit) {
          max_profit = max_profit_2 + profits[i];
        }
      }
    }

    return max_profit;
  }
};