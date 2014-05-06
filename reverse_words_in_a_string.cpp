class Solution {
public:
  void reverseWords(string &s) {
    reverse(s.begin(), s.end());

    string result;
    int len = s.length();
    int i = 0;

    // 跳过起始的空格
    while ((i < len) && (' ' == s[i])) {
      ++i;
    }

    for ( ; i < len; ) {
      int j = 0;  // 单词的长度

      while (((i + j) < len) && (s[i + j] != ' '))
      {
        ++j;
      }

      if (j >= 1) {
        if (!result.empty()) {
          result.push_back(' ');
        }

        for (int k = i + j - 1; k >= i; --k) {
          result.push_back(s[k]);
        }
      }

      i += j;

      // 继续跳空格
      while ((i < len) && (' ' == s[i])) {
        ++i;
      }
    }

    s = result;
  }
};