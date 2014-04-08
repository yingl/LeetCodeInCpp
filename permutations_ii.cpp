class Solution {
public:
  // 原理分析
  // 标准的排列组合就不说了，典型的递归求解。
  // 现在要求不重复，以[1, 1, 2, 3]为例
  // [1], [1, 2, 3]
  //   - [1, 1], [2, 3]
  //     - [1, 1, 2], [3] => [1, 1, 2, 3]
  //     - [1, 1, 3], [2] => [1, 1, 3, 2]
  // 重新排序，还原成[1, 1, 2, 3]
  // [2], [1, 1, 3]
  //   - [2, 1], [1, 3]
  //     - [2, 1, 1], [3] => [2, 1, 1, 3]
  //     - [2, 1, 3], [1] => [2, 1, 3, 1]
  // 重新排序，还原成[1, 1, 2, 3]
  // [3], [1, 1, 2]
  //   - [3, 1], [1, 2]
  //     - [3, 1, 1], [2] => [3, 1, 1, 2]
  //     - [3, 1, 2], [1] => [3, 1, 2, 1]
  void generate_permutation_unique(vector<int> &num,
      int index,
      vector<int> &permutation,
      vector<vector<int> > &results) {
    int size = num.size();

    if (size == index) {
      results.push_back(permutation);
    }
    else {
      for (int i = index; i < size; ++i) {
        if ((i > index) && (num[i] == num[index])) {
          continue;
        }
        else {
          swap(num[index], num[i]);  
        }

        permutation.push_back(num[index]);
        generate_permutation_unique(num, index + 1, permutation, results);
        permutation.pop_back();
      }

      sort(num.begin() + index, num.end());
    }
  }

  vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<vector<int> > results;
    vector<int> permutation;

    sort(num.begin(), num.end());
    generate_permutation_unique(num, 0, permutation, results);

    return results;
  }
};