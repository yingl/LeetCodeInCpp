class Solution {
public:
  int maximal_rectangle(vector<int> heights) {
    // 下面的代码参考largest_rectangle_in_histogram.cpp
    // 变量名略作规范
    int size = heights.size();

    if (0 == size) {
      return 0;
    }

    int result = INT_MIN;
    int index;
    stack<int> bars;

    for (int i = 0; i < size; ++i) {
      if (!bars.empty()) {
        // 如果堆栈顶部的元素比当前的高度高，弹出并计算可能的面积
        while ((!bars.empty()) && (heights[bars.top()] > heights[i])) {
          index = bars.top();
          bars.pop();

          if (bars.empty()) {
            result = max(result, i * heights[index]);
          }
          else {
            result = max(result, (i - bars.top() - 1) * heights[index]);
          }
        }
      }

      // 前面的元素必须小于等于当前元素
      bars.push(i);
    }

    while (!bars.empty()) {
      index = bars.top();
      bars.pop();

      if (bars.empty()) {
        result = max(result, size * heights[index]);
      }
      else {
        result = max(result, (size - bars.top() - 1) * heights[index]);
      }
    }

    return result;
  }

  int maximalRectangle(vector<vector<char> > &matrix) {
    if (0 == matrix.size()) {
      return 0;
    }

    int result = INT_MIN;
    int height = matrix.size();
    int width = matrix[0].size();
    int row;
    int col;
    vector<vector<int> > counts(height, vector<int>(width, 0));

    for (row = 0; row < height; ++row) {
      for (col = 0; col < width; ++col) {
        if (matrix[row][col] != '0') {
          if (0 == row) {
            counts[row][col] = 1;
          }
          else {
            // 每一行往上数，包括自己有几个1。
            counts[row][col] = counts[row - 1][col] + 1;
          }
        }
      }
    }

    for (row = 0; row < height; ++row) {
      result = max(result, maximal_rectangle(counts[row]));
    }

    return result;
  }
};