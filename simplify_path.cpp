class Solution {
public:
  string simplifyPath(string path) {
    string simplified_path = "/";
    vector<string> paths;
    int i = 0;
    int j;
    int len;

    while (path[i] != '\0') {
      if ('/' == path[i]) {
        // 目录往下一级
        ++i;
      }
      else {
        j = i + 1;

        while ((j < path.length()) && (path[j] != '/')) {
          ++j;
        }

        // 目录段的长度
        len = j - i;

        string dir = path.substr(i, len);

        if (dir != ".") {
          if (".." == dir) {
            if (!paths.empty()) {
              // "../"回退到上一层目录
              paths.pop_back();
            }
          }
          else {
            paths.push_back(dir);
          }
        }
        else {
          // "./"表示当前目录，直接忽略。
        }

        i = j;
      }
    }

    if (paths.size() > 0) {
      for (i = 0; i < (paths.size() - 1); ++i) {
        simplified_path += paths[i];
        simplified_path += "/";
      }

      simplified_path += paths[i];
    }

    return simplified_path;
  }
};