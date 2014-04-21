class Solution {
public:
  string minWindow(string S, string T) {
    int min_window = INT_MAX;
    int start;
    vector<int> target(256, 0);   // 字符串T的字符统计
    vector<int> status(256, 0);
    int i;
    int j;
    int matched = 0;  // 已匹配的字符数
    int s_len = S.length();
    int t_len = T.length();

    for (i = 0; i < t_len; ++i) {
      ++target[T[i]];
    }

    for (i = 0, j = 0; i < s_len; ++i) {
      if (matched < t_len) {
        if (status[S[i]] < target[S[i]]) {
          ++matched;
        }

        ++status[S[i]];
      }

      if (matched == t_len) {
        // 从头开始看哪些字符可以删除
        while ((j <= i) && (status[S[j]] > target[S[j]])) {
          --status[S[j]];
          ++j;
        }

        // 修正min_window
        if (min_window > (i - j + 1)) {
          min_window = i - j + 1;
          // 新字符串的开始位置
          start = j;
        }

        // 继续去除字符，直到matched小于t_len
        while ((j <= i) && (matched == t_len)) {
          --status[S[j]];

          if (status[S[j]] < target[S[j]]) {
            --matched;
          }

          ++j;
        }
      }
    }

    return (min_window != INT_MAX) ? S.substr(start, min_window) : "";
  }
};