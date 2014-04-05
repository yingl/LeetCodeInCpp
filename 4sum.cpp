class Solution {
public:
  vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int> > results;
    int i = 0;
    int size = num.size();

    sort(num.begin(), num.end());

    while (i < (size - 3)) {
      int pre_first = num[i];
      int j = i + 1;
      int tmp;

      while (j < (size - 2)) {
        int pre_second = num[j];
        int two_sum = pre_first + pre_second;
        int start = j + 1;
        int end = size - 1;
        
        while (start < end) {
          int left_val = num[start];
          int right_val = num[end];
          int four_sum = two_sum + left_val + right_val;

          if (four_sum < target) {
            ++start;
          }
          else if (four_sum > target) {
            --end;
          }
          else {
            vector<int> result;

            result.push_back(pre_first);
            result.push_back(pre_second);
            result.push_back(left_val);
            result.push_back(right_val);

            results.push_back(result);

            tmp = start + 1;

            while ((tmp < end) && (num[tmp] == num[start])) {
              ++tmp;
            }

            start = tmp;

            tmp = end - 1;

            while ((tmp > start) && (num[tmp] == num[end])) {
              --tmp;
            }

            end = tmp;
          }
        }

        tmp = j + 1;

        while ((tmp < (size - 2)) && (num[tmp] == num[j])) {
          ++tmp;
        }

        j = tmp;
      }

      tmp = i + 1;

      while ((tmp < (size - 3)) && (num[tmp] == num[i])) {
        ++tmp;
      }

      i = tmp;
    }

    return results;
  }
};