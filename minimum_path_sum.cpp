class Solution {
public:
  int minPathSum(vector<vector<int> > &grid) {
    int rows = grid.size();

    if (0 == rows) {
      return 0;
    }

    int cols = grid[0].size();
    int row;
    int col;

    for (row = 1; row < rows; ++row) {
      grid[row][0] += grid[row - 1][0];
    }

    for (col = 1; col < cols; ++col) {
      grid[0][col] += grid[0][col - 1];
    }

    for (row = 1; row < rows; ++row) {
      for (col = 1; col < cols; ++col) {
        grid[row][col] += min(grid[row - 1][col], grid[row][col - 1]);
      }
    }

    return grid[rows - 1][cols - 1];
  }
};