class Solution {
public:
  int removeDuplicates(int A[], int n) {
    int steps;

    for (int i = 1; i < n; ++i) {
      if (A[i] == A[i - 1]) {
        ++steps;
      }
      else {
        A[i - steps] = A[i];
      }
    }

    return n - steps;
  }
};