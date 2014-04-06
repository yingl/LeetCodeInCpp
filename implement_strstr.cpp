class Solution {
public:
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
};