class Solution {
public:
  bool isMatch(const char *s, const char *p) {
    bool star = false;  // *有没有出现过
    const char *saved_s = NULL;
    const char *saved_p = NULL;

    while (*s != '\0') {
      if (*p != '*') {
        if ((*s == *p) || ('?' == *p)) {
          ++s;
          ++p;
        }
        else {
          if (star) {
            // p固定在*之后的字符串，s则不断增长试图匹配。
            s = ++saved_s;
            p = saved_p + 1;
          }
          else {
            return false;
          }
        }
      }
      else {
        star = true;

        while ('*' == *p) {
          ++p;
        }

        saved_s = s;
        // 记录连续出现的最后一个*的位置
        saved_p = p - 1;
      }
    }

    // 处理p尾部的*
    while ('*' == *p) {
      ++p;
    }

    return (('\0' == *s) && ('\0' == *p));
  }
};