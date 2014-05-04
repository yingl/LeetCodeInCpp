class Solution {
public:
  // 这里必须假设hash的操作是O(1)的
  int consecutives(unordered_multimap<int, int> &hash,
      int value,
      bool ascending) { // true: 升序 false: 降序
    int count = 0;

    while (hash.count(value) > 0) {
      ++count;
      hash.erase(value);  // 非常重要！
      value += ascending ? 1: (-1);
    }

    return count;
  }
  int longestConsecutive(vector<int> &num) {
    int longest = 0;
    unordered_multimap<int, int> hash;
    int i;

    for (i = 0; i < num.size(); ++i) {
      hash.emplace(num[i], num[i]);
    }

    for (i = 0; i < num.size(); ++i) {
      if (hash.count(num[i]) > 0) {
        longest = max(longest,
            consecutives(hash, num[i], false) + 
                consecutives(hash, num[i] + 1, true));
      }
    }

    return longest;
  }
};