class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> result;
    map<int, vector<int> > indexes;
    int i, j, count = numbers.size();

    for (i = 0; i < count; ++i) {
      indexes[numbers[i]].push_back(i + 1);
    }

    sort(numbers.begin(), numbers.end());
      i = 0;
      j = count - 1;

    while (i < j) {
      int left_value = numbers[i], right_value = numbers[j];

      if ((left_value + right_value) < target) {
        ++i;
      }
      else if ((left_value + right_value) > target) {
        --j;
      }
      else {
        vector<int>::iterator left_it = indexes[left_value].begin();
        vector<int>::iterator right_it = indexes[right_value].begin();

        if (left_it == right_it) {
          ++right_it;
        }

        result.push_back((*left_it < *right_it) ? *left_it : *right_it);
        result.push_back((*left_it < *right_it) ? *right_it : *left_it);

        break;
      }
    }

    return result;
  }
};