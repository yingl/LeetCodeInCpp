class Solution {
public:
  int unique_paths_with_obstacles(const vector<vector<int> > &grid,
      int row,
      int col,
      vector<vector<int> > &paths) {
    if (0 == paths[row][col]) {
      if (0 == grid[row][col]) {
        if ((row - 1) >= 0) {
          paths[row][col] = unique_paths_with_obstacles(grid,
              row - 1,
              col,
              paths);
        }

        if ((col - 1) >= 0) {
          paths[row][col] += unique_paths_with_obstacles(grid,
              row,
              col - 1,
              paths);
        }
      }
    }
    
    return paths[row][col];
  }

  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    int rows = obstacleGrid.size();
    int cols = obstacleGrid[0].size();
    vector<vector<int> > paths(rows, vector<int>(cols, 0));

    paths[0][0] = (0 == obstacleGrid[0][0]) ? 1 : 0;

    return unique_paths_with_obstacles(obstacleGrid,
      rows - 1,
      cols - 1,
      paths);
  }
};