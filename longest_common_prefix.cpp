class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (0 == strs.size()) {
      return string();
    }

    int index = 0;
    bool stop = false;

    while (!stop) {
      char c = '\0';

      for (vector<string>::const_iterator it = strs.begin(); it != strs.end(); ++it) {
        if (index < it->length()) {
          if ('\0' == c) {
            c = (*it)[index];
          }
          else {
            if (c != (*it)[index]) {
              stop = true;
              break;
            }
          }
        }
        else {
          stop = true;
          break;
        }
      }

      ++index;
    }

    return strs[0].substr(0, index - 1);
  }
};