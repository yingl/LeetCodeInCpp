class Solution {
public:
  void merge(int A[], int m, int B[], int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while ((i >= 0) && (j >= 0)) {
      if (A[i] > B[j]) {
        A[k] = A[i];
        --i;
      }
      else {
        A[k] = B[j];
        --j;
      }

      --k;
    }

    if (j >= 0) {
      memcpy(A, B, (j + 1) * sizeof(int));
    }
  }
};