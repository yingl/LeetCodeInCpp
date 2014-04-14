class Solution {
public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> result;
    int height = matrix.size();
    int width;
    
    if (0 == height) {
      return result;
    }

    width = matrix[0].size();

    int top = 0;
    int down = height - 1;
    int left = 0;
    int right = width - 1;

    while ((top <= down) && (left <= right)) {
      int i;

      // 上
      for (i = left; i <= right; ++i) {
        result.push_back(matrix[top][i]);
      }

      // 右
      for (i = top + 1; i < down; ++i) {
        result.push_back(matrix[i][right]);
      }

      // 下
      if (top < down) {
        for (i = right; i >= left; --i) {
          result.push_back(matrix[down][i]);
        }
      }

      // 左
      if (left < right) {
        for (i = down - 1; i > top; --i) {
          result.push_back(matrix[i][left]);
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