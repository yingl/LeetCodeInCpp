class Solution {
public:
  int count_matches(const string &s,
      int s_index,
      const string &t,
      int t_index,
      vector<vector<int> > &matches) {
    if ('\0' == t[t_index]) {
      return 1;
    }
    else if ('\0' == s[s_index]) {
      return 0;
    }
    else {
      if (matches[s_index][t_index] != -1) {
        return matches[s_index][t_index];
      }

      int count = 0;

      for (int i = s_index; i < s.length(); ++i) {
        if (s[i] == t[t_index]) {
          count += count_matches(s, i + 1, t, t_index + 1, matches);
        }
      }

      matches[s_index][t_index] = count;

      return count;
    }
  }

  int numDistinct(string S, string T) {
    int s_len = S.length();
    int t_len = T.length();

    if ((0 == s_len) || (0 == t_len)) {
      return 0;
    }

    vector<vector<int> > matches(s_len, vector<int>(t_len, -1));

    return count_matches(S, 0, T, 0, matches);
  }
};