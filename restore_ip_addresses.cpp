class Solution {
public:
  void split_string(string &s,
      int index,
      vector<string> &segments,
      vector<string> &ips) {
    if ((4 == segments.size()) && ('\0' == s[index])) {
      string ip = "";

      for (int i = 0; i < 4; ++i) {
        ip += segments[i];

        if (i < 3) {
          ip += ".";
        }
      }

      ips.push_back(ip);
    }
    else {
      if ((segments.size() >= 4) && ('\0' != s[index])) {
        return;
      }

      for (int len = 1; (index + len) <= s.length(); ++len) {
        string segment = s.substr(index, len);
        int v = atoi(segment.c_str());

        if (v <= 255) {
          // x.0.x可以，x.0??.x不可以
          if ((segment.length() > 1) && ('0' == segment[0])) {
            continue;
          }

          segments.push_back(segment);
          split_string(s, index + len, segments, ips);
          segments.pop_back();
        }
        else {
          break;
        }
      }
    }
  }

  vector<string> restoreIpAddresses(string s) {
    vector<string> ips;
    vector<string> segments;

    split_string(s, 0, segments, ips);

    return ips;
  }
};