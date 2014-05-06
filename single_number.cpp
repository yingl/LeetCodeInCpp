class Solution {
public:
  int singleNumber(int A[], int n) {
    int result = A[0];

    for (int i = 1; i < n; ++i) {
      result ^= A[i];
    }

    return result;
  }
};