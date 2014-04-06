class Solution {
public:
  long long internal_divide(unsigned long long dividend, unsigned long long divisor) {
    if (dividend < divisor) {
      return 0;
    }

    long long result = 1;
    unsigned long long tmp = divisor;
    unsigned long long rest;

    while (tmp <= dividend) {
      rest = dividend - tmp;
      tmp <<= 1;

      if (tmp > dividend) {
        break;
      }
      else {
        result <<= 1;
      }
    }

    return result + internal_divide(rest, divisor);
  }

  int divide(int dividend, int divisor) {
    unsigned long long _dividend = abs((long long)dividend);
    unsigned long long _divisor = abs((long long)divisor);
    long long result = internal_divide(_dividend, _divisor);
    bool positive = (((dividend >= 0) && (divisor > 0)) || ((dividend < 0) && (divisor < 0)));

    return positive ? result : (-1) * result;
  }
};