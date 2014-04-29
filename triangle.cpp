class Solution {
public:
  int minimumTotal(vector<vector<int> > &triangle) {
    int min_total = INT_MAX;
    int levels = triangle.size();
    vector<int> sums(levels);
    int i;
    int j;

    sums[0] = triangle[0][0];

    for (i = 1; i < levels; ++i) {
      sums[i] = sums[i - 1] + triangle[i][i];

      for (j = i - 1; j > 0; --j) {
        sums[j] = min(sums[j - 1], sums[j]) + triangle[i][j];
      }

      sums[0] += triangle[i][0];
    }

    for (i = 0; i < levels; ++i) {
      if (sums[i] < min_total) {
        min_total = sums[i];
      }
    }

    return min_total;
  }
};