class Solution {
public:
  void generate_subsets(vector<int> &set,
      int index,
      vector<int> &subset,
      vector<vector<int> > &result) {
    for (int i = index; i < set.size(); ++i) {
      subset.push_back(set[i]);
      result.push_back(subset);

      if (i < (set.size() - 1)) {
        generate_subsets(set, i + 1, subset, result);
      }

      subset.pop_back();
    }
  }

  vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > result;
    vector<int> subset;

    if (0 == S.size()) {
      return result;
    }

    sort(S.begin(), S.end());
    // 空集一定是个子集
    result.push_back(subset);

    generate_subsets(S, 0, subset, result);

    return result;
  }
};