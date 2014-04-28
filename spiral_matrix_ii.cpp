class Solution {
public:
  vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > result(n, vector<int>(n));
    int i = 1;
    int top = 0;
    int down = n - 1;
    int left = 0;
    int right = n - 1;

    while ((top <= down) && (left <= right)) {
      int row;
      int col;

      // 上
      for (col = left; col <= right; ++col) {
        result[top][col] = i;
        ++i;
      }

      // 右
      for (row = top + 1; row < down; ++row) {
        result[row][right] = i;
        ++i;
      }

      // 下
      if (top < down) {
        for (col = right; col >= left; --col) {
          result[down][col] = i;
          ++i;
        }
      }

      // 左
      if (left < right) {
        for (row = down - 1; row > top; --row) {
          result[row][left] = i;
          ++i;
        }
      }

      ++top;
      --down;
      ++left;
      --right;
    }

    return result;
  }
};