class Solution {
public:
  vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> result;
    vector<vector<string> > lines;
    vector<string> line;
    int i;
    int j;

    for (i = 0; i < words.size(); ++i) {
      int len = 0;

      for (j = 0; j < line.size(); ++j) {
        len += line[j].length() + 1;
      }

      if ((len + words[i].length()) > L) {
        lines.push_back(line);
        line.clear();
      }

      line.push_back(words[i]);
    }

    if (line.size() > 0) {
      lines.push_back(line);
    }

    for (i = 0; i < lines.size(); ++i) {
      int spaces = L;
      int size = lines[i].size();
      string str = lines[i][0];  // 初始化字符串

      // 计算有多少个空格
      for (j = 0; j < size; ++j) {
        spaces -= lines[i][j].length();
      }

      for (j = 1; j < size; ++j) {
        if (i < (lines.size() - 1)) {
          int average_spaces = spaces / (size - j);
          int extra_spaces = spaces % (size - j);

          str.append(average_spaces, ' ');
          spaces -= average_spaces;

          if (extra_spaces > 0) {
            str.append(" ");
            spaces -= 1;
          }
        }
        else {
          // 最后一行特别处理
          if (j < size) {
            str.append(" ");
            spaces -= 1;
          }
          else {
            str.append(spaces, ' ');
            spaces = 0;
          }
        }

        str += lines[i][j];
      }

      if (spaces > 0) {
        str.append(spaces, ' ');
      }

      result.push_back(str);
    }

    return result;
  }
};