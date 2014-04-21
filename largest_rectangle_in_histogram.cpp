class Solution {
public:
  int largestRectangleArea(vector<int> &height) {
    int size = height.size();

    if (0 == size) {
      return 0;
    }

    int result = INT_MIN;
    int index;
    stack<int> bars;

    for (int i = 0; i < size; ++i) {
      if (!bars.empty()) {
        // 如果堆栈顶部的元素比当前的高度高，弹出并计算可能的面积
        while ((!bars.empty()) && (height[bars.top()] > height[i])) {
          index = bars.top();
          bars.pop();

          if (bars.empty()) {
            result = max(result, i * height[index]);
          }
          else {
            result = max(result, (i - bars.top() - 1) * height[index]);
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
        result = max(result, size * height[index]);
      }
      else {
        result = max(result, (size - bars.top() - 1) * height[index]);
      }
    }

    return result;
  }
};