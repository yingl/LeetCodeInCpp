class Solution {
public:
  int get_list_len(ListNode *head) {
    int len = 0;

    while (head != NULL) {
      head = head->next;
      ++len;
    }

    return len;
  }

  ListNode *rotateRight(ListNode *head, int k) {
    if (NULL == head) {
      return head;
    }

    // 小心k比链表长度大的情况
    k %= get_list_len(head);
    if (0 == k) {
      return head;
    }

    ListNode *first = head;
    ListNode *second = head;
    int i = 0;

    // second前进k步
    while (i < k) {
      second = second->next;
      ++i;
    }

    // 一起前进
    while (second->next != NULL) {
      first = first->next;
      second = second->next;
    }

    second->next = head;
    head = first->next;
    first->next = NULL;

    return head;
  }
};