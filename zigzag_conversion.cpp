class Solution {
public:
  string convert(string s, int nRows) {
    if (1 == nRows) {
      return s;
    }

    string result_str;
    vector<string> rows(nRows);
    int row = 0;
    int i = 0;
    bool down = true; // 控制方向

    while (i < s.length()) {
      rows[row].push_back(s[i]);
      ++i;

      if (0 == row) {
        down = true;
      }
      else if ((nRows - 1) == row) {
        down = false;
      }

      if (down) {
        ++row;
      }
      else {
        --row;
      }
    }

    for (row = 0; row < nRows; ++row) {
      result_str += rows[row];
    }

    return result_str;
  }
};