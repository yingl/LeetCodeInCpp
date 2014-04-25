class Solution {
public:
  int num_trees(int n, vector<int> &nums) {
    if (nums[n] > 0) {
      return nums[n];
    }

    if (n <= 1) {
      nums[n] = 1;
    }
    else {
      int num = 0;

      for (int i = 0; i < n; ++i) {
        num += (num_trees(i, nums) * num_trees(n - i - 1, nums));
      }

      nums[n] = num;
    }

    return nums[n];
  }

  int numTrees(int n) {
    vector<int> nums(n + 1, 0);

    nums[0] = 1;

    return num_trees(n, nums);
  }
};