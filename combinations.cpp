class Solution {
public:
  void generate_combinations(vector<int> &numbers,
      int index,
      int count,
      vector<int> combination,
      vector<vector<int> > &combinations) {
    if (0 == count) {
      combinations.push_back(combination);
    }
    else {
      for (int i = index; i <= (numbers.size() - count); ++i) {
        combination.push_back(numbers[i]);
        generate_combinations(numbers, i + 1, count - 1, combination, combinations);
        combination.pop_back();
      }
    }
  }

  vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > combinations;
    vector<int> combination;
    vector<int> numbers;

    for (int i = 1; i <= n; ++i) {
      numbers.push_back(i);
    }

    generate_combinations(numbers, 0, k, combination, combinations);

    return combinations;
  }
};