class Solution {
public:
    double pow(double x, int n) {
      if (0 == n) {
        return (double)1.0;
      }
      else if (1 == n) {
        return x;
      }
      else {
        double result;
        int abs_n = abs(n);

        if ((abs_n % 2) == 0) {
          // 偶数
          result = pow(x, abs_n / 2);
          result *= result;
        }
        else {
          // 奇数数
          result = pow(x, abs_n / 2);
          result *= result;
          result *= x;
        }

        return (n >= 0) ? result : (double)1.0 / result;
      }
    }
};