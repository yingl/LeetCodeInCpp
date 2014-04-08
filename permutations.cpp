class Solution {
public:
  void generate_permutation(vector<int> &num,
      int index,
      vector<int> &permutation,
      vector<vector<int> > &results) {
    int size = num.size();

    if (size == index) {
      results.push_back(permutation);
    }
    else {
      for (int i = index; i < size; ++i) {
        swap(num[index], num[i]);
        permutation.push_back(num[index]);
        generate_permutation(num, index + 1, permutation, results);
        permutation.pop_back();
        swap(num[index], num[i]);
      }
    }
  }

  vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > results;
    vector<int> permutation;

    generate_permutation(num, 0, permutation, results);

    return results;
  }
};