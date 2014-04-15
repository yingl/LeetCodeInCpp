class Solution {
public:
  bool isNumber(const char *s) {
    // 条件比较复杂，但实际就是个状态机。
    const int INIT = 0;
    const int INT = 10;           // 整数
    const int SYMBOL = 20;        // 正负号
    const int SINGLE_POINT = 30;  // 单个小数点
    const int FLOAT = 40;         // 浮点数
    const int EXP = 50;           // e
    const int EXP_INT = 60;       // e的整数次方
    const int EXP_SYMBOL = 70;    // e+/e-，等待后续内容
    const int ENDING_SPACES = 80;
    int state = INIT;

    while (*s != '\0') {
      char c = *s;

      switch (state) {
        case INIT:
          if ((c >= '0') && (c <= '9')) {
            state = INT;
          }
          else if (('+' == c) || ('-' == c)) {
            state = SYMBOL;
          }
          else if ('.' == c) {
            state = SINGLE_POINT;
          }
          else if (' ' != c) {
            return false;
          }

          break;
        case INT:
          if ((c < '0') || ( c > '9')) {
            if ('.' == c) {
              state = FLOAT;
            }
            else if ('e' == c) {
              state = EXP;
            }
            else if (' ' == c) {
              state = ENDING_SPACES;
            }
            else {
              return false;
            }
          }

          break;
        case SYMBOL:
          if ((c >= '0') && (c <= '9')) {
            state = INT;
          }
          else if ('.' == c) {
            state = SINGLE_POINT;
          }
          else {
            return false;
          }

          break;
        case SINGLE_POINT:
          if ((c >= '0') && (c <= '9')) {
            state = FLOAT;
          }
          else {
            return false;
          }

          break;
        case FLOAT:
          if ((c < '0') || (c > '9')) {
            if ('e' == c) {
              state = EXP;
            }
            else if (' ' == c) {
              state = ENDING_SPACES;
            }
            else {
              return false;
            }
          }

          break;
        case EXP:
          if ((c >= '0') && (c <= '9')) {
            state = EXP_INT;
          }
          else if (('+' == c) || ('-' == c)) {
            state = EXP_SYMBOL;
          }
          else {
            return false;
          }

          break;
        case EXP_INT:
          if ((c < '0') || (c > '9')) {
            if (' ' == c) {
              state = ENDING_SPACES;
            }
            else {
              return false;
            }
          }

          break;
        case EXP_SYMBOL:
          if ((c >= '0') && (c <= '9')) {
            state = EXP_INT;
          }
          else {
            return false;
          }

          break;
        case ENDING_SPACES:
          if (c != ' ') {
            return false;
          }

          break;
      }

      ++s;
    }

    return (INT == state) || \
        (FLOAT == state) || \
        (EXP_INT == state) || \
        (ENDING_SPACES == state);
  }
};