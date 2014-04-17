class Solution {
public:
  void setZeroes(vector<vector<int> > &matrix) {
    if (0 == matrix.size()) {
      return;
    }

    bool set_first_row = false; // 第一行是否要被清零
    bool set_first_col = false; // 第一列是否要被清零
    int height = matrix.size();
    int width = matrix[0].size();
    int row;
    int col;

    for (col = 0; col < width; ++col) {
      if (0 == matrix[0][col]) {
        set_first_row = true;
        break;
      }
    }

    for (row = 0; row < height; ++row) {
      if (0 == matrix[row][0]) {
        set_first_col = true;
        break;
      }
    }

    // 从第二行第二列开始扫描，如果某元素为0，把所在行和列的第一个元素置0.
    for (row = 1; row < height; ++row) {
      for (col = 1; col < width; ++col) {
        if (0 == matrix[row][col]) {
          matrix[0][col] = 0;
          matrix[row][0] = 0;
        }
      }
    }

    // 扫描第一行，如果元素为0，把所在列清零。
    for (col = 1; col < width; ++col) {
      if (0 == matrix[0][col]) {
        for (row = 1; row < height; ++row) {
          matrix[row][col] = 0;
        }
      }
    }

    // 扫描第一列，如果元素为0，把所在行清零。
    for (row = 1; row < height; ++row) {
      if (0 == matrix[row][0]) {
        for (col = 1; col < width; ++col) {
          matrix[row][col] = 0;
        }
      }
    }

    // 判断第一行和第一列是否需要清零
    if (set_first_row) {
      for (col = 0; col < width; ++col) {
        matrix[0][col] = 0;
      }
    }

    if (set_first_col) {
      for (row = 0; row < height; ++row) {
        matrix[row][0] = 0;
      }
    }
  }
};