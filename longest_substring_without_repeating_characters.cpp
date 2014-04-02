class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int len = s.length();
    int i = 0;
    int max_len = 0;

    while (i < len) {
      int len_of_substr = 1;
      int next = i + 1;
      vector<bool> marks(256, false);  // 记录是否有重复字符出现

      marks[s[i]] = true;

      while (next < len) {
        if (marks[s[next]]) {
          break;
        }

        marks[s[next]] = true;
        ++next;
        ++len_of_substr;
      }

      if (len_of_substr > max_len) {
        max_len = len_of_substr;
      }

      ++i;
    }

    return max_len;
  }
};