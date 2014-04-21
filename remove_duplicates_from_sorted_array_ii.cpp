class Solution {
public:
  int removeDuplicates(int A[], int n) {
    int count = n;
    int dup = 1;  // 相同的数字最多出现2次
    int steps = 0;

    for (int i = 1; i < n; ++i) {
      if (A[i] == A[i - 1]) {
        ++dup;

        if (dup <= 2) {
          A[i - steps] = A[i];  
        }
        else {
          ++steps;
          --count;  // 这个数要删除
        }
      }
      else {
        dup = 1;
        A[i - steps] = A[i];
      }
    }

    return count;
  }
};