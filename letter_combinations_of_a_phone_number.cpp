static char keys[8][4] = {{'a', 'b', 'c'},       // 2
    {'d', 'e', 'f'},       // 3
    {'g', 'h', 'i'},       // 4
    {'j', 'k', 'l'},       // 5
    {'m', 'n', 'o'},       // 6
    {'p', 'q', 'r', 's'},  // 7
    {'t', 'u', 'v'},       // 8
    {'w', 'x', 'y', 'z'}}; // 9
static int sizes[] = {3, 3, 3, 3, 3, 4, 3, 4}; 

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> results; 
    int levels = digits.size();     // 采用分层遍历法
    int current_level = 0;
    vector<int> indexes(levels, 0); // 记录每层得状态

    if (0 == levels) {
      return vector<string>(1, "");
    }

    // 已234为例，遍历顺序如下
    // adg
    // adh
    // adi
    // aeg
    // aeh
    // aei
    // afg
    // afh
    // afi
    // bdg
    // bdh
    // bdi
    // ...
    while (true) {
      // 键盘2是第0个元素
      int c_index = digits[current_level] - '0' - 2;

      if (sizes[c_index] == indexes[current_level]) {
        if (0 == current_level) {
          // 遍历结束
          break;
        }

        indexes[current_level] = 0;
        --current_level;
        ++indexes[current_level];

        continue;
      }
      else {
        string str;
        int i;

        if (current_level < (levels - 1)) {
          ++current_level;
        }
        else {
          for (i = 0; i < current_level; ++i) {
            str.push_back(keys[digits[i] - '0' - 2][indexes[i]]);
          }

          // 占位用
          str.push_back('?');

          for (i = 0; i < sizes[c_index]; ++i) {
            str[current_level] = keys[c_index][i];

            results.push_back(str);
          }

          indexes[current_level] = sizes[c_index];
        }
      }
    }

    return results;
  }
};