class Solution {
public:
  int extend(const string &str, int start, int end) {
    int len = str.length();
    int steps = 0;

    while ((start >= 0) && (end < len)) {
      if (str[start] == str[end]) {
        --start;
        ++end;
        ++steps;
      }
      else {
        break;
      }
    }

    return steps;
  }

  string longestPalindrome(string s) {
    int start = 0;
    int max_len = 0;

    for (int i = 0; i < s.length(); ++i) {
      int steps;
      int len_of_substr;

      steps = extend(s, i, i + 1);
      len_of_substr = steps * 2;

      if (len_of_substr > max_len) {
        start = i - steps + 1;
        max_len = len_of_substr;
      }

      steps = extend(s, i - 1, i + 1);
      len_of_substr = steps * 2 + 1;

      if (len_of_substr > max_len) {
        start = i - steps;
        max_len = len_of_substr;
      }
    }

    return s.substr(start, max_len);
  }
};