class Solution {
public:
  void generate_parenthesis(int n, 
      int number_of_left_pars,
      int number_of_right_pars,
      string &str,
      vector<string> &results) {
    if ((n == number_of_right_pars) && (n == number_of_right_pars)) {
      results.push_back(str);
    }

    if (number_of_left_pars < n) {
      str.push_back('(');
      generate_parenthesis(n, number_of_left_pars + 1, number_of_right_pars, str, results);
      str.pop_back();
    }

    if (number_of_right_pars < number_of_left_pars) {
      str.push_back(')');
      generate_parenthesis(n, number_of_left_pars, number_of_right_pars + 1, str, results);
      str.pop_back();
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> results;
    string str;

    generate_parenthesis(n, 0, 0, str, results);

    return results;
  }
};