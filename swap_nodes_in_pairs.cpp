class Solution {
public:
  void insert_two_nodes(ListNode *node_1,
      ListNode *node_2,
      ListNode *&head,
      ListNode *&tail) {
    if (NULL == head) {
      head = node_2;
      tail = node_2;
    }
    else {
      if (node_2 != NULL) {
        tail->next = node_2;
        tail = node_2;
      }
    }

    if (NULL == head) {
      head = node_1;
      tail = node_1;
    }
    else {
      tail->next = node_1;
      tail = node_1;
    }
  }

  ListNode *swapPairs(ListNode *head) {
    ListNode *swapped_head = NULL;
    ListNode *swapped_tail = NULL;

    while (head != NULL) {
      ListNode *node_1 = head;
      ListNode *node_2 = node_1 ? node_1->next : NULL;

      head = head->next;
      head = head ? head->next : NULL;

      insert_two_nodes(node_1, node_2, swapped_head, swapped_tail);
    }

    if (NULL != swapped_tail) {
      swapped_tail->next = NULL;
    }

    return swapped_head;
  }
};