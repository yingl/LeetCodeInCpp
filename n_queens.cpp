class Solution {
public:
  void solve_queens(int total_rows,
      int curr_row,
      vector<int> &solution,
      vector<vector<string> > &results) {
    int row;
    int col;

    if (curr_row == total_rows) {
      vector<string> strs(total_rows);

      for (row = 0; row < total_rows; ++row) {
        strs[row].append(solution[row], '.');
        strs[row].append(1, 'Q');
        strs[row].append(total_rows - solution[row] - 1, '.');
      }

      results.push_back(strs);
    }
    else {
      // 按列做检查
      for (col = 0; col < total_rows; ++col) {
        for (row = 0; row < curr_row; ++row) {
          // 不能在同一列上
          if (col == solution[row]) {
            break;
          }

          // 不能在相同的对角线上
          if (abs(curr_row - row) == abs(col - solution[row])) {
            break;
          }
        }

        if (row == curr_row) {
          solution[row] = col;
          solve_queens(total_rows, row + 1, solution, results);
        }
      }
    }
  }

  vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > results;
    vector<int> solution(n);

    solve_queens(n, 0, solution, results);

    return results;
  }
};