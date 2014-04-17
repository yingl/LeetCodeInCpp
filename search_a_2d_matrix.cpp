class Solution {
public:
  bool binary_search(vector<int> &row, int target) {
    int min = 0;
    int max = row.size() - 1;

    while (min <= max) {
      int mid = (min + max) / 2;

      if (row[mid] == target) {
        return true;
      }
      else if (row[mid] < target) {
        min = mid + 1;
      }
      else {
        max = mid - 1;
      }
    }

    return false;
  }

  // 确定在哪一行搜索
  int locate_row(const vector<vector<int> > &matrix, int target) {
    int rows = matrix.size();

    for (int row = 0; row < (rows - 1); ++row) {
      if ((target >= matrix[row][0]) && (target < matrix[row + 1][0])) {
        return row;
      }
    }

    return (target >= matrix[rows - 1][0]) ? (rows - 1) : -1;
  }

  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    int row = locate_row(matrix, target);

    if (row != -1) {
      return binary_search(matrix[row], target);
    }
    else {
      return false;
    }
  }
};