class Solution {
public:
  string getPermutation(int n, int k) {
    string result;
    vector<int> digits(n, 1);
    vector<int> factors(n, 1);  // 记录阶乘结果
    int i;

    // 初始化数字和阶乘表
    for (i = 1; i < n; ++i) {
      digits[i] = i + 1;
      factors[i] = i * factors[i - 1];
    }

    for (i = n - 1; i >= 0; --i) {
      // 确定第一个数字的位置
      int pos = (k - 1) / factors[i];

      result.push_back(digits[pos] + '0');
      digits.erase(digits.begin() + pos);
      k -= (pos * factors[i]);
    }

    return result;
  }
};