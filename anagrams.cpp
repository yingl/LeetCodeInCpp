class Solution {
public:
  // Anagrams就是季哥单词，如果每种字母出现的个数都相同，
  // 不考虑顺序，那么它们就是一类的。
  vector<string> anagrams(vector<string> &strs) {
    vector<string> results;
    map<string, int> dict;
    int size = strs.size();

    for (int i = 0; i < size; ++i) {
      string str = strs[i];

      sort(str.begin(), str.end());

      if (dict.find(str) != dict.end()) {
        int index = dict[str];

        if (index >= 0) {
          results.push_back(strs[index]);
          dict[str] = -1; // 已经输出，下次不需要再输出了。
        }

        results.push_back(strs[i]);
      }
      else {
        dict[str] = i;
      }
    }

    return results;
  }
};