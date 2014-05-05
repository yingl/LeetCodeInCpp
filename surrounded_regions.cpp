class Solution {
public:
  void mark(vector<vector<char> > &board, queue<pair<int, int> > &queue_of_o) {
    while (!queue_of_o.empty()) {
      pair<int, int> point = queue_of_o.front();
      int row = point.first;
      int col = point.second;
      int height = board.size();
      int width = board[0].size();

      queue_of_o.pop();

      if (((row >= 0) && (row < height)) && 
          ((col >= 0) && (col < width)) && 
          ('O' == board[row][col])) {
        board[row][col] = '#';

        queue_of_o.push(pair<int, int>(row - 1, col));
        queue_of_o.push(pair<int, int>(row + 1, col));
        queue_of_o.push(pair<int, int>(row, col - 1));
        queue_of_o.push(pair<int, int>(row, col + 1));
      }
    }
  }

  void solve(vector<vector<char> > &board) {
    // 原来采用DFS，但是由于测试用例修改，数据变大，会因为递归导致堆栈溢出，改为BFS。
    int height = board.size();

    if (0 == height) {
      return;
    }

    int width = board[0].size();
    int row;
    int col;
    queue<pair<int, int> > queue_of_o;

    for (row = 0; row < height; ++row) {
      // 第一列
      if ('O' == board[row][0]) {
        queue_of_o.push(pair<int, int>(row, 0));
        mark(board, queue_of_o);
      }

      // 最后一列
      if ('O' == board[row][width - 1]) {
        queue_of_o.push(pair<int, int>(row, width - 1));
        mark(board, queue_of_o);
      }
    }

    for (col = 0; col < width; ++col) {
      // 第一行
      if ('O' == board[0][col]) {
        queue_of_o.push(pair<int, int>(0, col));
        mark(board, queue_of_o);
      }

      // 最后一行
      if ('O' == board[height - 1][col]) {
        queue_of_o.push(pair<int, int>(height - 1, col));
        mark(board, queue_of_o);
      }
    }

    for (row = 0; row < height; ++row) {
      for (col = 0; col < width; ++col) {
        if ('O' == board[row][col]) {
          board[row][col] = 'X';
        }

        if ('#' == board[row][col]) {
          board[row][col] = 'O';
        }
      }
    }
  }
};