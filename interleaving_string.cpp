class Solution {
public:
  bool is_interleave(const char *s1,
      int s1_index,
      const char *s2,
      int s2_index,
      const char *s3,
      vector<vector<int> > &match_statuses) {
    if ('\0' == *s1) {
      return (0 == strcmp(s2, s3));
    }
    else if ('\0' == *s2) {
      return (0 == strcmp(s1, s3));
    }
    else {
      int status = match_statuses[s1_index][s2_index];

      if (status != 0) {
        return (status == 1);
      }

      bool match = false;

      if (*s1 == *s3) {
        match = is_interleave(s1 + 1, s1_index + 1, s2, s2_index, s3 + 1, match_statuses);
      }

      if ((match == false) && (*s2 == *s3)) {
        match = is_interleave(s1, s1_index, s2 + 1, s2_index + 1, s3 + 1, match_statuses);
      }

      match_statuses[s1_index][s2_index] = match ? 1 : -1;

      return match;      
    }
  }

  bool isInterleave(string s1, string s2, string s3) {
    int s1_size = s1.length();
    int s2_size = s2.length();
    int s3_size = s3.length();

    if ((s1_size + s2_size) != s3_size) {
      return false;
    }

    // 0: 未初始化
    // -1: 未匹配
    // 1: 匹配
    vector<vector<int> > match_statuses(s1_size, vector<int>(s2_size, 0));

    return is_interleave(s1.c_str(), 0, s2.c_str(), 0, s3.c_str(), match_statuses);
  }
};