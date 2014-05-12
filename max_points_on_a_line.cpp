class Solution {
public:
  int maxPoints(vector<Point> &points) {
    if (points.size() <= 2) {
      return points.size();
    }

    int max_points = INT_MIN;
    map<double, int> lines;

    for (int i = 0; i < (points.size() - 1); ++i) {
      int same_points = 0;
      int _max_points = 1;

      lines.clear();

      for (int j = i + 1; j < points.size(); ++j) {
        int x = points[i].x - points[j].x;
        int y = points[i].y - points[j].y;
        double slope = numeric_limits<double>::infinity();  // 偷懒的做法

        if ((0 ==x) && (0 == y)) {
          ++same_points;
        }
        else {
          if (y != 0) {
            slope = (double)x / (double)y;
          }

          int count = (lines.find(slope) != lines.end()) ? lines[slope] + 1: 2;

          lines[slope] = count;

          if (_max_points < count) {
            _max_points = count;
          }
        }
      }

      if (max_points < (_max_points + same_points)) {
        max_points = _max_points + same_points;
      }
    }

    return max_points;
  }
};