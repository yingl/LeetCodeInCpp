class Solution {
public:
  // 动态规划
  // 判断s[i, j]是否为回文的方法：
  //   1. s[i + 1, j - 1]是否为回文
  //   2. 如果1成了，判断s[i]是否等于s[j]。
  vector<vector<string>> partition(string s) {
    vector<vector<string> > result;
    vector<string> solution;
    int len = s.length();

    if (0 == len) {
      return result;
    }

    vector<vector<int> > pal_statuses(len, vector<int>(len, 0));

    _partition(s, 0, solution, result, pal_statuses);

    return result;
  }

protected:
  void _partition(string &s,
      int start,
      vector<string> &solution,
      vector<vector<string> > &result,
      vector<vector<int> > &pal_statuses) {
    int len = s.length();

    if (start >= len) {
      result.push_back(solution);
    }
    else {
      for (int i = start; i < len; ++i) {
        if (is_palindrome(s, start, i, pal_statuses)) {
          solution.push_back(s.substr(start, i - start + 1));
          _partition(s, i + 1, solution, result, pal_statuses);
          solution.pop_back();
        }
      }
    }
  }

  bool is_palindrome(string &s,
      int start,
      int end,
      vector<vector<int> > &pal_statuses) {
    if (start >= end) {
      if (start == end) {
        pal_statuses[start][end] = 1;
      }

      return true;
    }
    else {
      if (pal_statuses[start][end] != 0) {
        return (pal_statuses[start][end] > 0);
      }
      else {
        if (s[start] != s[end]) {
          pal_statuses[start][end] = -1;

          return false;
        }
        else {
          if (is_palindrome(s, start + 1, end - 1, pal_statuses)) {
            pal_statuses[start][end] = 1;
          }
          else {
            pal_statuses[start][end] = -1;
          }
        }

        return (pal_statuses[start][end] > 0);
      }
    }
  }
};