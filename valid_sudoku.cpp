class Solution {
public:
  bool isValidSudoku(vector<vector<char> > &board) {
    vector<int> marks;
    int row;
    int col;
    int block;
    int index;

    // Check by row
    for (row = 0; row < 9; ++row) {
      marks.assign(9, 0);

      for (col = 0; col < 9; ++col) {
        if ('.' == board[row][col]) {
          continue;
        }

        index = board[row][col] - '1';
        ++marks[index];

        if (marks[index] > 1) {
          return false;
        }
      }
    }

    // Checl by column
    for (col = 0; col < 9; ++col) {
      marks.assign(9, 0);

      for (row = 0; row < 9; ++row) {
        if ('.' == board[row][col]) {
          continue;
        }

        index = board[row][col] - '1';
        ++marks[index];

        if (marks[index] > 1) {
          return false;
        }
      }
    }

    // Check by block
    for (block = 0; block < 9; ++block) {
      marks.assign(9, 0);

      for (row = (block / 3) * 3; row < (block / 3) * 3 + 3; ++row) {
        for (col = (block % 3) * 3; col < (block % 3) * 3 + 3; ++col) {
          if ('.' == board[row][col]) {
            continue;
          }

          index = board[row][col] - '1';
          ++marks[index];

          if (marks[index] > 1) {
            return false;
          }
        }
      }
    }
    return true;
  }
};