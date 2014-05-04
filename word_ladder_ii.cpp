class Solution {
protected:
  void build_ladder(unordered_map<string, vector<string> > &traces,
      const string &word,
      vector<string> &ladder,
      vector<vector<string> > &ladders) {
    if (0 == traces[word].size()) {
      ladder.push_back(word);

      vector<string> tmp = ladder;

      reverse(tmp.begin(), tmp.end());
      ladders.push_back(tmp);

      ladder.pop_back();
    }
    else {
      ladder.push_back(word);

      for (vector<string>::iterator it = traces[word].begin();
          it != traces[word].end(); ++it) {
        build_ladder(traces, *it, ladder, ladders);
      }

      ladder.pop_back();
    }
  }

public:
  // 分层BFS遍历，同时记录前缀，当某一层出现end时结束，生成ladder。
  vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
    vector<vector<string> > ladders;
    unordered_map<string, vector<string> > traces;
    unordered_set<string> levels[2];
    int curr = 0;
    int prev = 1;

    for (unordered_set<std::string>::iterator it = dict.begin();
        it != dict.end();
        ++it) {
      traces[*it] = vector<string>();
    }

    levels[curr].insert(start);

    while (true) {
      swap(curr, prev);

      for (unordered_set<string>::iterator it = levels[prev].begin();
          it != levels[prev].end();
          ++it) {
        dict.erase(*it);
      }

      levels[curr].clear();

      for (unordered_set<string>::iterator it = levels[prev].begin();
          it != levels[prev].end();
          ++it) {
        for (size_t pos = 0; pos < it->size(); ++pos) {
          string word = *it;

          for (char c = 'a'; c <= 'z'; ++c) {
            if (word[pos] == c) {
              continue;
            }

            word[pos] = c;

            if ((dict.count(word) > 0) || (word == end)) {
              traces[word].push_back(*it);
              levels[curr].insert(word);
            }
          }
        }
      }

      if (0 == levels[curr].size()) {
        return ladders;
      }

      if (levels[curr].count(end) > 0) {
        break;
      }
    }

    vector<string> ladder;

    build_ladder(traces, end, ladder, ladders);

    return ladders;
  }
};