class Solution {
public:
  /*
  char *strStr(char *haystack, char *needle) {
    int h_len = strlen(haystack);
    int n_len = strlen(needle);

    if (0 == n_len) {
      return haystack;
    }

    for (int i = 0; i <= (h_len - n_len); ++i) {
      if (0 == strncmp(haystack + i, needle, n_len)) {
        return haystack + i;
      }
    }

    return NULL;
  }
  */

  // Using KMP method!
  char *strStr(char *haystack, char *needle) {
    int h_len = strlen(haystack);
    int n_len = strlen(needle);

    if (0 == n_len) {
      return haystack;
    }

    vector<int> next(n_len);

    generate_next(next, needle);

    for (int i = 0, j = 0; i < h_len; ++i) {
      // 算法核心，向前找到匹配位置。
      while ((j > 0) && (haystack[i] != needle[j])) {
        j = next[j - 1];
      }

      // 如果相等，needle的索引位置往后移动一位。
      if (haystack[i] == needle[j]) {
        ++j;
      }

      if (j == n_len) {
        return haystack + i - j + 1;
      }
    }

    return NULL;
  }

protected:
  void generate_next(vector<int> &next, char *needle) {
    int n_len = strlen(needle);

    // 因为第一个元素没有前缀后缀，所以永远是0。
    next[0] = 0;

    for (int i = 1, j = 0; i < n_len; ++i) {
      // j代表部分[0, i]的部分匹配值
      // 当i和j指向的字符不匹配时，next向前遍历，直到两个字符相等或j等于0.
      while ((j > 0) && (needle[i] != needle[j])) {
        j = next[j - 1];
      }

      // 如果i和j指向的字符相等，那么j增加1。
      if (needle[i] == needle[j]) {
        ++j;
      }

      next[i] = j;
    }
  }
};