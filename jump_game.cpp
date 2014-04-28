class Solution {
public:
  bool canJump(int A[], int n) {
    vector<bool> marks(n, false);

    if (1 == n) {
      return true;
    }

    marks[0] = (A[0] > 0);

    for (int i = 1; i < n; ++i) {
      if (!marks[i]) {
        for (int j = i - 1; j >= 0; --j) {
          if (marks[j]) {
            if ((j + A[j]) >= i) {
              marks[i] = true;
              break;
            }
          }
        }
      }
    }

    return marks[n - 1];
  }
};