class Solution {
public:
  bool isScramble(string s1, string s2) {
    if (s1.length() != s2.length()) {
      return false;
    }

    int len = s1.length();
    vector<vector<vector<bool> > > scramble_status(len, vector<vector<bool> >(len, vector<bool>(len)));
    int i;
    int j;
    int k;
    int sub_len;

    // 先对长度为1的子串进行判定并保存结果，
    // 然后对字串长度不断增加，直到等于len，
    // 利用递推算出结果。
    for (i = 0; i < len; ++i) {
      for (j = 0; j < len; ++j) {
        scramble_status[0][i][j] = (s1[i] == s2[j]);
      }
    }

    for (sub_len = 2; sub_len <= len; ++sub_len) {
      for (i = len - sub_len; i >= 0; --i) {
        for (j = len - sub_len; j >= 0; --j) {
          bool scramble = false;

          for (k = 1; (k < sub_len) && !scramble; ++k) {
            scramble = scramble_status[k - 1][i][j]  && scramble_status[sub_len - k - 1][i + k][j + k];
            scramble = scramble || (scramble_status[k - 1][i][j + sub_len - k] && scramble_status[sub_len - k - 1][i + k][j]);
          }

          scramble_status[sub_len - 1][i][j] = scramble;
        }
      }
    }

    return scramble_status[len - 1][0][0];
  }
};