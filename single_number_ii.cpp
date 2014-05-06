class Solution {
public:
  int singleNumber(int A[], int n) {
    int one = 0;  // 该bit出现1时置1
    int two = 0;  // 该bit出现2次1时置1
    int xthree;   // 当该bit在one和two上都是1时，置0，否则置1

    for (int i = 0; i < n; ++i) {
      two |= (one & A[i]);
      one ^= A[i];
      xthree = ~(one & two);
      one &= xthree;
      two &= xthree;
    }

    return one;
  }
};