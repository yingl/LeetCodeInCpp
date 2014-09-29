class Solution {
public:
  int maxProduct(int A[], int n) {
    if (1 == n) {
      return A[0];
    }
    
    int max_product;
    int positive_max = 0; // 正的最大值
    int negtive_min = 0;  // 负的最小值

    for (int i = 0; i < n; ++i) {
      if (A[i] < 0) {
        // 交换，为后面可能遇到的负数做准备
        swap(positive_max, negtive_min);
      }

      positive_max = max(positive_max * A[i], A[i]);
      negtive_min = min(negtive_min * A[i], A[i]);
      max_product = max(max_product, positive_max);
    }

    return max_product;
  }
};