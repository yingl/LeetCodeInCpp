class Solution {
public:
  int threeSumClosest(vector<int> &num, int target) {
    int closest;
    int min_diff = INT_MAX;
    int i = 0;
    int size = num.size();

    sort(num.begin(), num.end());

    while (i < (size - 2)) {
      int pre_number = num[i];
      int start = i + 1;
      int end = size - 1;

      while (start < end) {
        int left_val = num[start];
        int right_val = num[end];
        int sum = pre_number + left_val + right_val;
        int diff = abs(sum - target);

        if (0 == diff) {
          return target;
        }

        if (diff <= min_diff) {
          min_diff = diff;
          closest = sum;
        }

        if (sum < target) {
          ++start;
        }
        else {
          --end;
        }
      }

      ++i;
    }

    return closest;
  }
};