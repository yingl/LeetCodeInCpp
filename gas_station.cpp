class Solution {
public:
  // 这里有一个重要的假设，如果从某个a点出发到b点失败，
  // 那么a到b任何一点都不能成功。证明~~~自己google之。
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int number = gas.size();

    for (int i = 0; i < number; ++i) {
      int j = i;
      int count = 1;
      int gas_count = 0;

      while (count <= number) {
        if ((gas_count + gas[j % number]) >= cost[j % number]) {
          if (count == number) {
            return i;
          }

          gas_count += (gas[j % number] - cost[j % number]);
          ++j;
          ++count;
        }
        else {
          i = j;  // 从j后面一个站点开始
          break;
        }
      }
    }

    return -1;
  }
};