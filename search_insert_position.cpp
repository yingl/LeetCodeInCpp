class Solution {
public:
  int searchInsert(int A[], int n, int target) {
    int start = 0;
    int end = n - 1;
    int mid;

    while (start <= end) {
      mid = (start + end) / 2;

      if (A[mid] == target) {
        return mid;
      }
      else if (A[mid] < target) {
        start = mid + 1;
      }
      else {
        end = mid - 1;
      }
    }

    return (A[mid] > target) ? mid : mid + 1;
  }
};