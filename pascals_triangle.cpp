class Solution {
public:
  vector<vector<int> > generate(int numRows) {
    vector<vector<int> > triangle;

    if (numRows <= 0) {
      return triangle;
    }

    triangle.push_back(vector<int>(1, 1));

    for (int row = 1; row < numRows; ++row) {
      triangle.push_back(vector<int>(row + 1));
      triangle[row][0] = 1;
      triangle[row][row] = 1;

      for (int col = 1; col < row; ++col) {
        triangle[row][col] = triangle[row - 1][col - 1] + triangle[row - 1][col];
      }
    }

    return triangle;
  }
};