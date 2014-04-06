class Solution {
public:
  vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> results;
    int l_size = L.size();
    

    if (l_size <= 0) {
      return results;
    }

    map<string, int> count_of_word_for_l;
    map<string, int> count_of_word_for_s;
    int word_len = L[0].length();
    int i;
    int j;

    for (i = 0; i < l_size; ++i) {
      ++count_of_word_for_l[L[i]]; // 统计L里每个单词出现的次数
    }

    for (i = 0; i <= (int)S.length() - (word_len * l_size); ++i) {
      count_of_word_for_s.clear();

      for (j = 0; j < l_size; ++j) {
        string word = S.substr(i + j * word_len, word_len);

        if (count_of_word_for_l.find(word) != count_of_word_for_l.end()) {
          ++count_of_word_for_s[word];

          if (count_of_word_for_s[word] > count_of_word_for_l[word]) {
            break;
          }
        }
        else {
          break;
        }
      }

      if (j == l_size) {
        results.push_back(i);
      }
    }

    return results;
  }
};