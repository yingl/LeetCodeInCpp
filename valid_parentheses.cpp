class Solution {
public:
  bool isValid(string s) {
    stack<char> left_pars;
    const char *str = s.c_str();

    while (*str != '\0') {
      char c = *str;

      if (('(' == c) || ('[' == c) || ('{' == c)) {
        left_pars.push(c);
      }
      else {
        if (left_pars.empty()) {
          return false;
        }

        char expected;

        switch (c) {
          case ')':
            expected = '(';
            break;
          case ']':
            expected = '[';
            break;
          case '}':
            expected = '{';
            break;
        }

        if (left_pars.top() == expected) {
          left_pars.pop();
        }
        else {
          return false;
        }
      }

      ++str;
    }

    return left_pars.empty();
  }
};