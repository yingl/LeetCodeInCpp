class Solution {
public:
  int find_kth_number(int array_a[], int start_of_a, int end_of_a, int array_b[], int start_of_b, int end_of_b, int k) {
    if (start_of_a > end_of_a) {
      return array_b[start_of_b + k - 1];
    }
    else if (start_of_b > end_of_b) {
      return array_a[start_of_a + k - 1];
    }
    else {
      int mid_of_a = (start_of_a + end_of_a) / 2;
      int mid_of_b = (start_of_b + end_of_b) / 2;
      int len_of_first_half_of_a = mid_of_a - start_of_a + 1;
      int len_of_first_half_of_b = mid_of_b - start_of_b + 1;
      int len_of_first_half = len_of_first_half_of_a + len_of_first_half_of_b;

      if (len_of_first_half > k) {
        if (array_a[mid_of_a] > array_b[mid_of_b]) {
          // 第k个数在a的前半部分和b的全部里找
          return find_kth_number(array_a, 
              start_of_a,
              mid_of_a - 1,
              array_b,
              start_of_b,
              end_of_b,
              k);
        }
        else {
          // 第k个数在b的前半部分和a的全部里找
          return find_kth_number(array_a,
              start_of_a,
              end_of_a,
              array_b,
              start_of_b,
              mid_of_b - 1,
              k);
        }
      }
      else {
        if (array_a[mid_of_a] > array_b[mid_of_b]) {
          // 第k个数在a的全部和b的后半部分找
          return find_kth_number(array_a,
              start_of_a,
              end_of_a,
              array_b,
              mid_of_b + 1,
              end_of_b,
              k - (len_of_first_half_of_b));
        }
        else {
          // 第k个数在b的全部和a的后半部分找
          return find_kth_number(array_a, mid_of_a + 1, end_of_a, array_b, start_of_b, end_of_b, k - (len_of_first_half_of_a));
        }
      }
    }
  }

  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    bool even = (((m + n) % 2) == 0); // 判断总数是否为偶数。
    int mid = even ? (m + n) / 2 : (m + n) /2 + 1;  // 中间数位置

    int v_1 = find_kth_number(A, 0, m - 1, B, 0, n - 1, mid);

    if (!even) {
      return v_1;
    }
    else {
      int v_2 = find_kth_number(A, 0, m - 1, B, 0, n - 1, mid + 1);

      return (double)(v_1 + v_2) / 2.0f;
    }
  }
};