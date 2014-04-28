class Solution {
public:
  bool merge(Interval &left, Interval &right) {
    if ((right.start <= left.start) && (right.end >= left.start)) {
      left.start = right.start;
      left.end = (left.end > right.end) ? left.end : right.end;
    }
    else if ((right.start >= left.start) && (right.start <= left.end)) {
      left.end = (left.end > right.end) ? left.end : right.end;
    }
    else {
      return false;
    }

    return true;
  }

  vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> result;

    for (int i = 0; i < intervals.size(); ++i) {
      for (int j = result.size() - 1; j >= 0; --j) {
        if (merge(intervals[i], result[j])) {
          result.erase(result.begin() + j);
        }
      }

      result.push_back(intervals[i]);
    }

    return result;
  }
};