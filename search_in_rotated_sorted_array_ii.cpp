class Solution {
public:
  bool binary_search(int array[], int start, int end, int target) {
    if (start > end) {
      return false;
    }

    int mid = (start + end) / 2;
    bool found = false;

    if (array[mid] == target) {
      return true;
    }
    else if (array[mid] < target) {
      if (array[start] <= target) {
        found = binary_search(array, start, mid - 1, target);
      }

      if (found) {
        return true;
      }

      found = binary_search(array, mid + 1, end, target);

      if (found) {
        return true;
      }
    }
    else {
      found = binary_search(array, start, mid - 1, target);

      if (found) {
        return true;
      }

      if (array[end] >= target) {
        found = binary_search(array, mid + 1, end, target);
      }

      if (found) {
        return true;
      }
    }

    return false;
  }

  bool search(int A[], int n, int target) {
    return binary_search(A, 0, n - 1, target);
  }
};