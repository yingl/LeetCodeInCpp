class Solution {
public:
  int maxSubArray(int A[], int n) {
    int max = INT_MIN;
    int i;
    int j;

    for (int i = 0; i < n; ) {
      int sub_sum = 0;

      j = i;

      do {
        sub_sum += A[j];

        if (sub_sum > max) {
          max = sub_sum;
        }

        ++j;
      } while ((j < n) && (sub_sum > 0));

      i = j;
    }

    return max;
  }
};