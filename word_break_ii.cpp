class Solution {
public:
  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    vector<string> result;
    vector<string> path;
    int len = s.length();
    vector<bool> match(len + 1, false);
    vector<list<int> > lookup(len + 1);

    match[0] = true;

    for (int i = 1; i <= len; ++i) {
      for (int prev = 0; prev < i; ++prev) {
        if (match[prev] && (dict.find(s.substr(prev, i - prev)) != dict.end())) {
          // 找到一个匹配的单词
          match[i] = true;
          lookup[i].push_back(prev);
        }
      }
    }

    if (!match[len]) {
      return result;
    }

    back_trace(s, len, lookup, path, result);
  }

protected:
  void back_trace(string &s,
      int index,
      vector<list<int> > &lookup,
      vector<string> &path,
      vector<string> &result) {
    if (0 == index) {
      string str;
      int size = path.size();

      for (int i = size - 1; i >= 0; --i) {
        str.append(path[i]);

        if (i != 0) {
          str.append(" ");
        }
      }

      result.push_back(str);
    }
    else {
      for (list<int>::iterator it = lookup[index].begin();
          it != lookup[index].end();
          ++it) {
        int prev = *it;

        path.push_back(s.substr(prev, index - prev));
        back_trace(s, prev, lookup, path, result);
        path.pop_back();
      }
    }
  }
};