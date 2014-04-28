class Solution {
public:
  bool is_alphabets(char c) {
    return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'));
  }

  int lengthOfLastWord(const char *s) {
    int len = 0;
    bool found = false;

    for (int i = strlen(s) - 1; i >= 0; --i) {
      char c = s[i];

      if (is_alphabets(c)) {
        if (!found) {
          found = true;
        }

        ++len;
      }
      else {
        if (found) {
          break;
        }
      }
    }

    return len;
  }
};