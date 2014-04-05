class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (1 == k) {
      return head;
    }

    ListNode *p = head;
    ListNode *prev = NULL;

    while (p != NULL) {
      ListNode *first_node = p;
      ListNode *kth_node = first_node;

      for (int i = 1; i < k; ++i) {
        kth_node = kth_node->next;

        if (NULL == kth_node) {
          if (prev != NULL) {
            prev->next = first_node;
          }

          return head;
        }
      }

      if (NULL == prev) {
        head = kth_node;
      }

      p = kth_node->next;

      ListNode *tmp_head = NULL;
      ListNode *tmp_tail = NULL;
      ListNode *tmp = NULL;

      while (first_node != kth_node) {
        tmp = first_node->next;

        if (NULL == tmp_head) {
          tmp_head = first_node;
          tmp_tail = first_node;
          tmp_tail->next = NULL;
        }
        else {
          first_node->next = tmp_head;
          tmp_head = first_node;
        }

        first_node = tmp;
      }

      kth_node->next = tmp_head;
      tmp_head = kth_node;

      if (prev != NULL) {
        prev->next = tmp_head;
      }

      prev = tmp_tail;
    }

    return head;
  }
};