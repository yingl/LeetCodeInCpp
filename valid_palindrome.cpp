class Solution {
public:
  void to_low(string &s) {
    for (int i = 0; i < s.length(); ++i) {
      if ((s[i] >= 'A') && (s[i] <= 'Z')) {
        s[i] += 'a' - 'A';
      }
    }
  }

  bool is_alphanumeric(char c) {
    return (((c >= 'a') && (c <= 'z')) || ((c >= '0') && (c <= '9')));
  }

  bool isPalindrome(string s) {
    int i = 0;
    int j = s.length() - 1;

    to_low(s);

    while (i < j) {
      if (!is_alphanumeric(s[i])) {
        ++i;
        continue;
      }
      else if (!is_alphanumeric(s[j])) {
        --j;
        continue;
      }
      else {
        if (s[i] != s[j]) {
          return false;
        }
        else {
          ++i;
          --j;
        }
      }
    }

    return true;
  }
};