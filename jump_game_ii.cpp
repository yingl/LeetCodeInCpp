class Solution {
public:
  int calc_steps(int array[], int target, vector<int> &steps) {
    if (-1 != steps[target]) {
      return steps[target];
    }

    int min = INT_MAX;

    for (int i = target - 1; i >= 0; --i) {
      if ((i + array[i]) >= target) {
        // 典型的动态规划啊！
        if ((calc_steps(array, i, steps) + 1) < min) {
          min = steps[i] + 1;
        }
      }
    }

    steps[target] = min;

    return min;
  }

  int jump(int A[], int n) {
    vector<int> steps(n, -1); // 每一个点走几步可以到达

    // 初始化steps
    steps[0] = 0;
    for (int i = 1; i <= min(A[0], n - 1); ++i) {
      steps[i] = 1;
    }

    calc_steps(A, n - 1, steps);

    return steps[n - 1];
  }
};