class Solution {
public:
  string multiply(string num1, string num2) {
    if (("0" == num1) || ("0" == num2)) {
      return "0";
    }

    // 模仿竖式乘法
    string result = "";
    int i;
    int j;
    int flag = 0;       // 进位标记
    int steps = 0;      // 移位数，用来表示十百千万...

    for (i = num1.length() - 1; i >= 0; --i) {
      int position = steps; // 结果数组当前的位置

      for (j = num2.length() - 1; j >= 0; --j) {
        int val = (num1[i] - '0') * (num2[j] - '0') + flag;

        if (position < result.length()) {
          val += result[position] - '0';
          result[position] = (val % 10) + '0';
        }
        else {
          result.append(1, (val % 10) + '0');
        }

        flag = val / 10;
        ++position;
      }

      // 单独处理最后一个进位
      if (flag > 0) {
        result.append(1, flag + '0');
      }

      flag = 0;
      ++steps;
    }

    reverse(result.begin(), result.end());

    return result;
  }
};