class Solution {
public:
  void append_to_tail(ListNode *node, ListNode *&head, ListNode *&tail) {
    if (NULL == head) {
      head = node;
      tail = node;
    }
    else {
      tail->next = node;
      tail = node;
    }
  }

  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = NULL;
    ListNode *tail = NULL;
    int sum;
    int flag = 0; // 标志进位

    while ((l1 != NULL) || (l2 != NULL)) {
      sum = ((l1 != NULL) ? l1->val : 0) + ((l2 != NULL) ? l2->val : 0) + flag;
      flag = sum / 10;

      append_to_tail(new ListNode(sum % 10), head, tail);

      l1 = (l1 != NULL) ? l1->next : NULL;
      l2 = (l2 != NULL) ? l2->next : NULL;
    }

    if (flag > 0) {
      append_to_tail(new ListNode(flag), head, tail);
    }

    return head;
  }
};