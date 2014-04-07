class Solution {
public:
  // 原理分析
  // 以162543为例，下一个应该是163245
  // 步骤如下：
  // 1. 找到最后一个num[i] < num[i + 1]的点。
  // 2. 如果第一步没找到，说明已经是最后一个排练，直接逆序返回即可。
  // 3. 从num[i + 1]到num[size - 1]找到大于num[i]的最小的数，并与num[i]交换位置。
  // 4. 对num[i + 1]到num[size - 1]排序。
  void nextPermutation(vector<int> &num) {
    int size =num.size();
    int first_index = -1;
    int second_index = -1;
    int min = INT_MAX;
    int i;

    if (size <= 1) {
      return;
    }

    for (i = 0; i < (size - 1); ++i) {
      if (num[i] < num[i + 1]) {
        first_index = i;
      }
    }

    if (-1 == first_index) {
      reverse(num.begin(), num.end());
    }
    else {
      for (i = first_index + 1; i < size; ++i) {
        if (num[i] > num[first_index]) {
          if (num[i] < min) {
            min = num[i];
            second_index = i;
          }
        }
      }

      swap(num[first_index], num[second_index]);
      sort(num.begin() + first_index + 1, num.end());
    }
  }
};