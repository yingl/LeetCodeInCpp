class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    vector<int> result;
    int flag = 1;
    int sum;

    for (int i = digits.size() - 1; i >= 0; --i) {
      sum = digits[i] + flag;
      result.push_back(sum % 10);
      flag = sum / 10;
    }

    if (flag > 0) {
      result.push_back(1);
    }

    reverse(result.begin(), result.end());

    return result;
  }
};