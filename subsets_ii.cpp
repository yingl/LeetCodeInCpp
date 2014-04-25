class Solution {
public:
  void generate_subsets(vector<int> &set,
      int index,
      vector<int> &subset,
      vector<vector<int> > &subsets) {
    int size = set.size();

    for (int i = index; i < size; ) {
      subset.push_back(set[i]);
      subsets.push_back(subset);

      if ((i + 1) < size) {
        generate_subsets(set, i + 1, subset, subsets);
      }

      subset.pop_back();

      int j = i + 1;

      while ((j < size) && (set[i] == set[j])) {
        ++j;
      }

      i = j;
    }
  }

  vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int> > subsets;
    vector<int> subset;

    if (0 == S.size()) {
      return subsets;
    }

    sort(S.begin(), S.end());
    // 空集一定是个子集
    subsets.push_back(subset);

    generate_subsets(S, 0, subset, subsets);

    return subsets;
  }
};