class Solution {
public:
  int candy(vector<int> &ratings) {
    int sum = 0;
    int number = ratings.size();
    vector<int> candies(number, 1); // 每人至少1粒糖

    for (int i = 1; i < number; ++i) {
      if (ratings[i] > ratings[i - 1]) {
        candies[i] = candies[i - 1] + 1;
      }
    }

    for (int i = number - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) {
        if (candies[i] <= candies[i + 1]) {
          candies[i] = candies[i + 1] + 1;
        }
      }
    }

    for (int i = 0; i < number; ++i) {
      sum += candies[i];
    }

    return sum;
  }
};