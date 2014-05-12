class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> results;

    for (int i = 0; i < tokens.size(); ++i) {
      string token = tokens[i];

      if (is_operator(token)) {
        int val_1;
        int val_2;

        val_2 = results.top();
        results.pop();
        val_1 = results.top();
        results.pop();

        results.push(do_op(val_1, val_2, token));
      }
      else {
        results.push(atoi(token.c_str()));
      }
    }

    return results.top();
  }

protected:
  bool is_operator(string &token) {
    char op = token[0];

    return (1 == token.length()) && 
        (('+' == op) ||
         ('-' == op) ||
         ('*' == op) ||
         ('/' == op));
  }

  int do_op(int val_1, int val_2, string &token) {
    char op = token[0];

    switch(op) {
      case '+':
        return val_1 + val_2;
      case '-':
        return val_1 - val_2;
      case '*':
        return val_1 * val_2;
      default:  // '/'
        return val_1 / val_2;
    }
  }
};