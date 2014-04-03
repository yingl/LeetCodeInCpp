class Solution {
public:
  int romanToInt(string s) {
    int result = 0;
    int mul = 0;  // 处理个十百千位
    char one;
    char five;
    char ten;
    const char *str = s.c_str();

    while (*str != '\0') {
      char c = *str;

      if ('M' == c) {
        // 1000
        mul = 1000;
        one = 'M';
        five = '?';
        ten = '?';
      }
      else if (('C' == c) || ('D' == c)) {
        // 100
        mul = 100;
        one = 'C';
        five = 'D';
        ten = 'M';
      }
      else if (('X' == c) || ('L' == c)) {
        // 10
        mul = 10;
        one = 'X';
        five = 'L';
        ten = 'C';
      }
      else {
        // 1
        mul = 1;
        one = 'I';
        five = 'V';
        ten = 'X';
      }

      int tmp;

      if (one == c) {
        tmp = 1;
        ++str;

        while ((*str != '\0') && (one == *str)) {
          ++tmp;
          ++str;
        }

        if (ten == *str) {
          result += (mul * 9);
          ++str;
        }
        else if (five == *str) {
          result += (mul * 4);
          ++str;
        }
        else {
          result += (mul * tmp);
        }
      }
      else if (five == c) {
        tmp = 5;
        ++str;

        while ((*str != '\0') && (one == *str)) {
          ++tmp;
          ++str;
        }

        result += (mul * tmp);
      }
    }

    return result;
  }
};