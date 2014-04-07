class Solution {
public:
  bool is_in_range(const pair<int, int> &range, const pair<int, int> &sub_range) {
    return ((range.first <= sub_range.first) && (range.second >= sub_range.second));
  }

  int calc_volume(int bars[], const pair<int, int> &range) {
    int start = range.first;
    int end = range.second;
    int volume = min(bars[start], bars[end]) * (end - start - 1);

    // Range范围内其他柱子的高度必须小于等于min(bars[start], bars[end])。
    for (int i = start + 1; i < end; ++i) {
      volume -= bars[i];
    }

    return volume;
  }

  int trap(int A[], int n) {
    stack<pair<int, int> > ranges;
    stack<int> bar_positions;

    for (int i = 0; i < n; ++i) {
      if (bar_positions.empty()) {
        bar_positions.push(i);
      }
      else {
        if (A[i] < A[bar_positions.top()]) {
          // 比栈顶元素小，继续压入。
          bar_positions.push(i);
        }
        else {
          int start;
          pair<int, int> range;

          while (!bar_positions.empty()) {
            start = bar_positions.top();

            if (A[start] > A[i]) {
              break;
            }

            // 弹出所有小于等于A[i]的元素
            bar_positions.pop();
          }

          // 注意，这里要分两种情况：
          // 1. A[start]被弹出，那么[start, i]正好构成一个区间，并且这之间的数一定小于A[start]。
          // 2. A[start]没有被弹出，[start, i]构成一个区间，并且有可能合并更多区间。
          bar_positions.push(i);
          range.first = start;
          range.second = i;

          while (!ranges.empty()) {
            // 可重叠的子区间弹出
            if (is_in_range(range, ranges.top())) {
              ranges.pop();
            }
            else {
              break;
            }
          }

          ranges.push(range);
        }
      }
    }

    int volume = 0;

    while (!ranges.empty()) {
      volume += calc_volume(A, ranges.top());
      ranges.pop();
    }

    return volume;
  }
};