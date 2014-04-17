class Solution {
public:
  bool is_overflow(int dividend, int divisor, int result) {
    return (dividend / divisor) != result;
  }

  int sqrt(int x) {
    int result;
    int min = 0;
    int max = x;
    int square;

    if (x <= 1) {
      return x;
    }

    while (min <= max) {
      result = (min + max) / 2;
      square = result * result;

      if (is_overflow(square, result, result)) {
        max = result - 1;
        continue;
      }

      if (square == x) {
        return result;
      }
      else if (square < x) {
        min = result + 1;
      }
      else {
        max = result - 1;
      }
    }

    return (square < x) ? result : (result - 1); 
  }
};