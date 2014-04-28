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

  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> result;
    bool inserted = false;

    for (int i = 0; i < intervals.size(); ++i) {
      if (!inserted) {
        if (merge(newInterval, intervals[i])) {
          result.push_back(newInterval);
          inserted = true;
        }
        else {
          if (newInterval.end < intervals[i].start) {
            result.push_back(newInterval);
            inserted = true;
            --i;
          }
          else {
            result.push_back(intervals[i]);
          }
        }
      }
      else {
        int size = result.size();

        if (!merge(result[size - 1], intervals[i])) {
          result.push_back(intervals[i]);
        }
      }
    }

    if (!inserted) {
      result.push_back(newInterval);
    }

    return result;
  }
};