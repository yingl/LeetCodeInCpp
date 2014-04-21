class Solution {
public:
  bool search_word(vector<vector<char> > &board,
      int row,
      int col,
      const char *word,
      vector<vector<bool> > &visit_statuses) {
    if ('\0' == *word) {
      return true;
    }

    int height = board.size();
    int width = board[0].size();
    int prev_row = row - 1;
    int next_row = row + 1;
    int prev_col = col - 1;
    int next_col = col + 1;

    // 向上探索
    if (prev_row >= 0) {
      if ((!visit_statuses[prev_row][col]) && (board[prev_row][col] == *word)) {
        visit_statuses[prev_row][col] = true;

        if (search_word(board, prev_row, col, word + 1, visit_statuses)) {
          return true;
        }

        visit_statuses[prev_row][col] = false;
      }
    }

    // 向下探索
    if (next_row < height) {
      if ((!visit_statuses[next_row][col]) && (board[next_row][col] == *word)) {
        visit_statuses[next_row][col] = true;

        if (search_word(board, next_row, col, word + 1, visit_statuses)) {
          return true;
        }

        visit_statuses[next_row][col] = false;
      }
    }

    // 向左探索
    if (prev_col >= 0) {
      if ((!visit_statuses[row][prev_col]) && (board[row][prev_col] == *word)) {
        visit_statuses[row][prev_col] = true;

        if (search_word(board, row, prev_col, word + 1, visit_statuses)) {
          return true;
        }

        visit_statuses[row][prev_col] = false;
      }
    }

    // 向右探索
    if (next_col < width) {
      if ((!visit_statuses[row][next_col]) && (board[row][next_col] == *word)) {
        visit_statuses[row][next_col] = true;

        if (search_word(board, row, next_col, word + 1, visit_statuses)) {
          return true;
        }

        visit_statuses[row][next_col] = false;
      }
    }

    return false;
  }

  bool exist(vector<vector<char> > &board, string word) {
    if (0 == board.size()) {
      return false;
    }

    int height = board.size();
    int width = board[0].size();
    vector<vector<bool> > visit_statuses(height, vector<bool>(width, false));

    for (int row = 0; row < height; ++row) {
      for (int col = 0; col < width; ++col) {
        if (board[row][col] == word[0]) {
          visit_statuses[row][col] = true;

          if (search_word(board, row, col, word.c_str() + 1, visit_statuses)) {
            return true;
          }

          visit_statuses[row][col] = false;
        }
      }
    }

    return false;
  }
};