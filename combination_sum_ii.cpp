class Solution {
public:
  // 参考Combination Sum，这里更简单，同一个数不需要重复使用。
  void combination_sum_2(vector<int> &num,
      int target,
      int start,
      int sum,
      vector<int> &combination,
      vector<vector<int> > &results) {
    int size = num.size();

    if (sum == target) {
      results.push_back(combination);
    }
    else if ((start < size) && (sum < target)) {
      for (int i = start; i < size; ) {
        int val = num[i];

        combination.push_back(val);
        // 变化在这步
        combination_sum_2(num, target, i + 1, sum + val, combination, results);
        combination.pop_back();

        // 这里还是需要考虑去重，考虑num = [1, 1, 2]，target = 2的情况。
        int j = i + 1;

        while (j < size) {
          if (val == num[j]) {
            ++j;
          }
          else {
            break;
          }
        }

        i = j;
      }
    }
  }

  vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    vector<vector<int> > results;
    vector<int> combination;

    // 这里排序是为了保证输出顺序
    sort(num.begin(), num.end());

    combination_sum_2(num, target, 0, 0, combination, results);

    return results;
  }
};