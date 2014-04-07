class Solution {
public:
  string countAndSay(int n) {
    string results[2];
    int current = 0;  // 两个buffer来回切换
    int next = 1;

    results[current] = "1"; // 初始条件

    for (int i = 1; i < n; ++i) {
      int len = results[current].length();

      for (int j = 0; j < len; ) {
        int c = results[current][j];
        int k = j + 1;
        int sum = 1;

        // 开始计数
        while (k < len) {
          if (results[current][k] == c) {
            ++k;
            ++sum;
          }
          else {
            break;
          }
        }

        // 放心，不会出现sum两位数的情况。
        results[next].append(1, '0' + sum);
        results[next].append(1, c);

        j = k;
      }

      swap(current, next);
      results[next].clear();
    }

    return results[current];
  }
};