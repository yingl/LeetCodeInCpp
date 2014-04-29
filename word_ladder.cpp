class Solution {
public:
  // 广度优先搜索
  int ladderLength(string start, string end, unordered_set<string> &dict) {
    int len = 1;
    int curr = 0;
    int next = 1;
    queue<string> ladders[2];

    ladders[curr].push(start);

    while ((dict.size() > 0) && (!ladders[curr].empty())) {
      while (!ladders[curr].empty()) {
        string str(ladders[curr].front());

        ladders[curr].pop();

        for (int i = 0; i < str.size(); ++i) {
          for (char c = 'a'; c <= 'z'; ++c) {
            if (c == str[i]) {
              continue;
            }

            char tmp = str[i];

            str[i] = c;

            if (str == end) {
              return len + 1;
            }
            else {
              if (dict.count(str) > 0) {
                ladders[next].push(str);
                dict.erase(str);
              }
            }

            str[i] = tmp;
          }
        }
      }

      swap(curr, next);
      ++len;
    }

    return 0;
  }
};