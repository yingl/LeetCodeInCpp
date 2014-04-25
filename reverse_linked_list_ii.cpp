class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode *next_start = head;
    ListNode *prev = NULL;
    int i = 0;
    int j = 0;

    if (m == n) {
      return head;
    }      

    // 向前走到第m个节点
    while (i < (m - 1)) {
      prev = next_start;
      next_start = next_start->next;
      ++i;
    }

    // 反转m到n的区间
    ListNode *new_head = NULL;
    ListNode *new_tail = NULL;

    while (j <= (n - m)) {
      if (NULL == new_head) {
        new_head = next_start;
        new_tail = next_start;
        next_start = next_start->next;
      }
      else {
        ListNode *tmp = next_start;
        next_start = next_start->next;
        tmp->next = new_head;
        new_head = tmp;
      }

      ++j;
    }

    if (new_tail != NULL) {
      new_tail->next = next_start;
    }

    if (prev != NULL) {
      prev->next = new_head;

      return head;
    }
    else {
      return new_head;
    }
  }
};