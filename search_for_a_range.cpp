class Solution {
public:
  int binary_search(int array[], int start, int end, int target) {
    while (start <= end) {
      int mid = (start + end) / 2;

      if (array[mid] < target) {
        start = mid + 1;
      }
      else if (array[mid] > target) {
        end = mid - 1;
      }
      else {
        return mid;
      }
    }

    return -1;
  }

  vector<int> searchRange(int A[], int n, int target) {
    vector<int> result(2, -1);
    int position = binary_search(A, 0, n - 1, target);

    if (-1 == position) {
      return result;
    }

    int tmp = position - 1;
    result[0] = position;
    result[1] = position;

    // 搜索[0, position - 1]
    while (tmp >= 0) {
      tmp = binary_search(A, 0, tmp, target);

      if (-1 == tmp) {
        break;
      }
      else {
        result[0] = tmp;  // 可能的开始位置
        --tmp;
      }
    }

    tmp = position + 1;

    // 搜索后半段
    while (tmp < n) {
      tmp = binary_search(A, tmp, n - 1, target);

      if (-1 == tmp) {
        break;
      }
      else {
        result[1] = tmp;  // 可能的结束位置
        ++tmp;
      }
    }

    return result;
  }
};