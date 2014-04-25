class Solution {
public:
  int calc_decode_ways(string &s,
      int index,
      vector<int> &cached_ways) {
    int len = s.length();

    if (index >= len) {
      return 1;
    }
    else if (cached_ways[index] >= 0) {
      return cached_ways[index];
    }
    else {
      int v1 = s[index] - '0';
      int v2 = -1;

      if (0 == v1) {
        cached_ways[index] = 0;
        return 0;
      }
      else {
        int ways = calc_decode_ways(s, index + 1, cached_ways);

        if ((index + 1) < len) {
          v2 = v1 * 10 + (s[index + 1] - '0');

          if ((v1 >= 1) && (v2 <= 26)) {
            ways += calc_decode_ways(s, index + 2, cached_ways);
          }
        }

        cached_ways[index] = ways;

        return ways;
      }
    }
  }

  int numDecodings(string s) {
    int len = s.length();

    if (0 == len) {
      return 0;
    }

    vector<int> cached_ways(len, -1);

    calc_decode_ways(s, 0, cached_ways);

    return cached_ways[0];
  }
};