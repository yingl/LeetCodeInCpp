class Solution {
public:
  // 原理分析
  // 以)(()())为例子：
  // 1. 堆栈1：记录当前左括号位置和有效括号对长度
  // 2. 最长长度longest = -1。
  // 3. 0-): 堆栈1的大小为0，无法匹配，抛弃。
  // 4. 1-(: 压入堆栈1，当前长度为0，堆栈1内元素为((1, 0))。
  // 5. 2-(: 压入堆栈1，当前长度为0，堆栈1内元素为((1, 0), (2, 0))。
  // 6. 3-): 堆栈1的大小大于0，正好可以匹配。弹出一个元素，当前配对长度为(3 - 2 + 0 ＋ 1 = 2)，longest = 2。
  //         3: 当前右括号位置。
  //         2: 当前左括号位置。
  //         0: 之前有效括号对长度。
  //         1: 索引修正。
  // 7. 4-(: 压入堆栈1，当前长度为2，堆栈内元素为((1, 0), (4, 2))。
  // 8. 5-): 堆栈1的大小大于0，正好可以匹配。弹出一个元素，当前配对长度为(5 - 4 + 2 ＋ 1 = 4)，longest = 4。
  int longestValidParentheses(string s) {
    int longest = 0;
    int current = 0;
    int max = - 1;
    stack<pair<int, int> > records;   // 记录当前左括号位置和有效括号对长度

    for (int i = 0; i < s.length(); ++i) {
      if ('(' == s[i]) {
        records.push(pair<int, int>(i, current));
        current = 0;
      }
      else {
        current = 0;

        if (records.size() > 0) {
          pair<int, int> record = records.top();

          current = i - record.first + record.second + 1;
          records.pop();

          if (current > longest) {
            longest = current;
          }
        }
      }
    }

    return longest;
  }
};