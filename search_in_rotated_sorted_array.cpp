class Solution {
public:
  // 原理分析
  // 以4567012里找6为例子：
  // 判断数组是否顺序，满足条件直接二分法。
  // 寻找分界(pivotal)点，满足a[i] < a[i - 1]并且a[i] > a[i + 1]。
  // 比较要找的数和A[0]，大的话在［0， i - 1]区间找，小的话在[i, n - 1]区间找。
  int find_pivotal(int array[], int start, int end) {
    if (start >= end) {
      return start;
    }

    int mid = (start + end) / 2;

    if (array[mid] >= array[start]) {
      if (array[mid] >= array[0]) {
        return find_pivotal(array, mid + 1, end);
      }
      else {
        return find_pivotal(array, start, mid - 1);
      }
    }
    else {
      return find_pivotal(array, start, mid);
    }
  }

  int binary_search(int array[], int target, int start, int end) {
    while (start <= end) {
      int mid = (start + end) / 2;

      if (array[mid] < target) {
        return binary_search(array, target, mid + 1, end);
      }
      else if (array[mid] > target) {
        return binary_search(array, target, start, mid - 1);
      }
      else {
        return mid;
      }
    }

    return -1;
  }

  int search(int A[], int n, int target) {
    // 处理顺序和只有一个元素的情况
    if (A[0] <= A[n - 1]) {
      return binary_search(A, target, 0, n - 1);
    }

    int pivotal = find_pivotal(A, 0, n - 1);

    if (target >= A[0]) {
      return binary_search(A, target, 0, pivotal - 1);
    }
    else {
      return binary_search(A, target, pivotal, n - 1);
    }
  }
};