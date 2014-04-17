class Solution {
public:
  void sortColors(int A[], int n) {
    const int RED = 0;
    const int WHITE = 1;
    const int BLUE = 2;
    int red_index = 0;
    int blue_index = n - 1;
    int i = 0;

    // 思路就是把红的放到前面，蓝的放到后面。
    while (i <= blue_index) {
      int color = A[i];

      if (RED == color) {
        swap(A[i], A[red_index]);

        ++i;
        ++red_index;  // 下次发现红色可以放置的位置
      }
      else if (BLUE == color) {
        swap(A[i], A[blue_index]);

        --blue_index; // 下次发现蓝色可以放置的位置

        // 先不要动i，因为i的位置上有可能出现红色，可以继续像前放置。
      }
      else {
        // 白色不动
        ++i;
      }
    }
  }
};