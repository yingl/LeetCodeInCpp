static const char* quick_check_table[4][9] = {{"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, // 1 - 9
    {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, // 10 - 90
    {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, // 100 - 900
    {"M", "MM", "MMM"}}; // 1000 - 3000

class Solution {
public:
  string intToRoman(int num) {
    string roman;
    int level = 0;  // 个十百千位标记

    while (num > 0) {
      int i = num % 10;

      if (i > 0) {
        roman = string(quick_check_table[level][i - 1]) + roman;
      }

      num /= 10;
      ++level;
    }

    return roman;
  }
};