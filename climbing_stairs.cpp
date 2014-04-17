class Solution {
public:
  int climbStairs(int n) {
    if ((0 == n) || (1 == n)) {
      return 1;
    }
    else if (2 == n) {
      return 2;
    }
    else {
      int steps;
      int n0 = 1;
      int n1 = 2;

      for (int i = 2; i < n; ++i) {
        steps = n0 + n1;
        n0 = n1;
        n1 = steps;
      }

      return steps;
    }
  }
};