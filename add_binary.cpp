class Solution {
public:
  string addBinary(string a, string b) {
    string result;
    int bit;
    int flag = 0;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    const char *a_str = a.c_str();
    const char *b_str = b.c_str();

    while ((*a_str != '\0') && (*b_str != '\0')) {
      bit = (*a_str - '0') + (*b_str - '0') + flag;
      result.push_back((bit % 2) + '0');
      flag = bit / 2;

      ++a_str;
      ++b_str;
    }

    const char *p = ('\0' == *a_str) ? b_str : a_str;

    while (*p != '\0') {
      bit = (*p - '0') + flag;
      result.push_back((bit % 2) + '0');
      flag = bit / 2;

      ++p;
    }

    if (flag > 0) {
      result.push_back('1');
    }

    reverse(result.begin(), result.end());

    return result;
  }
};