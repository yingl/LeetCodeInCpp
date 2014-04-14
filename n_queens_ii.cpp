class Solution {
public:
  void total_n_queens(int total_rows,
      int curr_row,
      vector<int> &solution,
      int &result) {
    int row;
    int col;

    if (curr_row == total_rows) {
      ++result;
    }
    else {
      for (col = 0; col < total_rows; ++col) {
        for (row = 0; row < curr_row; ++row) {
          if (col == solution[row]) {
            break;
          }

          if (abs(curr_row - row) == abs(col - solution[row])) {
            break;
          }
        }

        if (row == curr_row) {
          solution[row] = col;
          total_n_queens(total_rows, row + 1, solution, result);
        }
      }
    }
  }

  int totalNQueens(int n) {
    int result = 0;
    vector<int> solution(n);

    total_n_queens(n, 0, solution, result);

    return result;
  }
};