class Solution {
public:
  int min_distance(string word_1,
      int index_1,
      string word_2,
      int index_2,
      vector<vector<int> > &cached_distances) {
    int len_1 = word_1.length();
    int len_2 = word_2.length();

    if (index_1 >= len_1) {
      // 字符串1已经到了尾部，距离就是字符串2剩下的长度。
      return (len_2 - index_2);
    }
    else if (index_2 >= len_2) {
      return (len_1 - index_1);
    }

    if (cached_distances[index_1][index_2] > 0) {
      return cached_distances[index_1][index_2];
    }
    else {
      // word_1或者word_2插入一个字符，取较小值。
      int dist_1 = 1 + min(min_distance(word_1, index_1, word_2, index_2 + 1, cached_distances),
          min_distance(word_1, index_1 + 1, word_2, index_2, cached_distances));

      // 如果word_1[index_1]不等于word_2[index_2]，则做一次修改，继续比较取较小值。
      int dist_2 = min_distance(word_1, index_1 + 1, word_2, index_2 + 1, cached_distances);
      if (word_1[index_1] != word_2[index_2]) {
        dist_2 += 1;
      }

      cached_distances[index_1][index_2] = min(dist_1, dist_2);
    }
  }

  int minDistance(string word1, string word2) {
    // 保存计算结果，空间换时间。
    vector<vector<int> > cached_distances(word1.length(), vector<int>(word2.length(), -1));

    return min_distance(word1, 0, word2, 0, cached_distances);
  }
};