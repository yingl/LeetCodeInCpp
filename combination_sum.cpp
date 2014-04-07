class Solution {
public:
  // 原理分析
  // 显然是个递归问题。
  // 以［2, 3, 6, 7]，目标为7举例：
  // [2]，[2, 3, 6, 7] => 5
  // [2, 2], [3, 6, 7] => 3
  // [2]. [3, 6, 7] => 5
  // ...
  void combination_sum(vector<int> &candidates,
      int target,
      int start,
      int sum,
      vector<int> &combination,
      vector<vector<int> > &results) {
    int size = candidates.size();

    if (sum == target) {
      results.push_back(combination);
    }
    else if ((start < size) && (sum < target)) {
      for (int i = start; i < size; ) {
        int val = candidates[i];

        combination.push_back(val);
        combination_sum(candidates, target, i, sum + val, combination, results);
        combination.pop_back();

        // 重复的数字跳过
        int j = i + 1;

        while (j < size) {
          if (candidates[i] == candidates[j]) {
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

  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<vector<int> > results;
    vector<int> combination;

    // 排序使得我们可以正确的处理重复的数字
    sort(candidates.begin(), candidates.end());

    combination_sum(candidates, target, 0, 0, combination, results);

    return results;
  }
};