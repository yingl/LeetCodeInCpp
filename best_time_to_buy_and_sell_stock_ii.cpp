class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int profit = 0;
    int size = prices.size();
    int buy_price = -1;
    int i;

    for (i = 0; i < (size - 1); ++i) {
      if (-1 == buy_price) {
        if (prices[i] < prices[i + 1]) {
          buy_price = prices[i];
        }
        else {
          continue;
        }
      }
      else {
        if (prices[i] > prices[i + 1]) {
          profit += prices[i] - buy_price;
          buy_price = -1;
        }
      }
    }

    if (buy_price != -1) {
      profit += prices[i] - buy_price;
    }

    return profit;
  }
};