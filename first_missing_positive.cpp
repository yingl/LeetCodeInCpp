class Solution {
public:
  // 原理分析
  // 难点在于O(n)的时间复杂度和O(1)的空间复杂度。
  // 办法也很简单，就是不断交换位置：
  // 1. 数组大小为size
  // 2. 如果A[i] < 0或者A[i] > size或者A[i] = i - 1，不处理。
  // 3. 对于A[i]，如果A[i] > 0并且A[i] <= size，把A[i]和A[A[i] - 1]交换，再检查交换后的A[i]是否要继续做交换。
  // 4. 顺序遍历数组，找到第一个不满足A[i] = i + 1的数。
  int firstMissingPositive(int A[], int n) {
    if (0 == n) {
      return 1;
    }

    int i;

    for (i = 0; i < n; ++i) {
      int val = A[i];

      if (val != (i + 1)) {
        while ((val > 0) && (val <= n) && (A[val - 1] != val)) {
          int tmp = A[val - 1];

          A[val - 1] = val;
          val = tmp;
        }
      }
    }

    for (i = 0; i < n; ++i) {
      if (A[i] != (i + 1)) {
        return i + 1;
      }
    }

    return n + 1;
  }
};