class Solution {
public:
  int unique_paths(int x, int y, vector<vector<int> > &paths) {
    if (0 == paths[x][y]) {
      if ((x - 1) >= 0) {
        paths[x][y] += unique_paths(x - 1, y, paths);
      }

      if ((y - 1) >= 0) {
        paths[x][y] += unique_paths(x, y - 1, paths);
      }
    }
    
    return paths[x][y];
  }
  int uniquePaths(int m, int n) {
    vector<vector<int> > paths(m, vector<int>(n, 0));

    paths[0][0] = 1;

    return unique_paths(m - 1, n - 1, paths);
  }
};