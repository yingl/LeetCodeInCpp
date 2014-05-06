class Solution {
public:
  int minCut(string s) {
    int len = s.length();

    vector<int> cuts(len + 1);
    vector<vector<bool> > pal_statuses(len, vector<bool>(len, false));

    for (int i = 0; i <= len; ++i) {
      // 从第i个元素开始后面最多可以切几次
      cuts[i] = len - i;
    }

    for (int i = len - 1; i >= 0; --i) {
      for (int j = i; j < len; ++j) {
        if ((s[i] == s[j]) && 
            (((j - i) <= 1) || (pal_statuses[i + 1][j - 1]))) {
          pal_statuses[i][j] = true;
          // 因为s[i, j]是回文，所以1 + cuts[j + 1]有可能是更好选择
          cuts[i] = min(cuts[i], 1 + cuts[j + 1]);
        }
      }
    }

    return cuts[0] - 1;
  }
};