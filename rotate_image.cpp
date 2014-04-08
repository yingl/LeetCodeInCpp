class Solution {
public:
  void rotate(vector<vector<int> > &matrix) {
    int n = matrix.size();

    if (n <= 1) {
      return;
    }

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;

    while ((top < bottom) && (left < right)) {
      int steps = right - left + 1;

      for (int i = left; i < right; ++i) {
        int tmp = matrix[top][i];

        steps = i - left;
        matrix[top][i] = matrix[bottom - steps][left];
        matrix[bottom -steps][left] = matrix[bottom][right - steps];
        matrix[bottom][right - steps] = matrix[top + steps][right];
        matrix[top + steps][right] = tmp;
      }

      ++top;
      --bottom;
      ++left;
      --right;
    }
  }
};