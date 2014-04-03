class Solution {
public:
  int atoi(const char *str) {
    bool minus = false; // 不确定的情况下先假设为正数

    while (' ' == *str) {
      // 先消除头上连续的空格
      ++str;
    }

    // 判断正负数
    if (('+' ==  *str) || ('-' == *str)) {
      if ('-' == *str) {
        minus = true;
      }

      ++str;
    }

    // 有非数字就返回0
    if (('\0' == *str) || (*str < '0') || (*str > '9')) {
      return 0;
    }

    unsigned long long ull = 0; // 小心溢出，我们这里处理32位数。

    while (*str != '\0') {
      // 遇到非数字就中止
      if ((*str < '0') || (*str > '9')) {
        break;
      }

      ull = ull * 10 + (*str - '0');

      if (minus) {
        if (ull > 0x80000000) {
          // 负数溢出
          return INT_MIN;
        }
      }
      else {
        if (ull > 0x7fffffff) {
          // 正数溢出
          return INT_MAX;
        }
      }

      ++str;
    }

    return minus ? -1 * (int)ull : (int)ull;
  }
};