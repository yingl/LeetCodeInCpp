class Solution {
public:
  int reverse(int x) {
    bool minus = (x < 0); // 是否负数
    int result = 0;

    x = abs(x);

    while (x > 0) {
      result = result * 10 + x % 10;
      x /= 10;
    }

    return minus ? -result : result;
  }
};