class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = NULL;
    ListNode *tail = NULL;
    ListNode *tmp;

    while ((l1 != NULL) && (l2 != NULL)) {
      if (l1->val < l2->val) {
        tmp = l1;
        l1 = l1->next;
      }
      else {
        tmp = l2;
        l2 = l2->next;
      }

      if (NULL == head) {
        head = tmp;
        tail = tmp;
      }

      tail->next = tmp;
      tail = tmp;
    }

    tmp = (NULL == l1) ? l2 : l1;
    if (tail != NULL) {
      tail->next = tmp;
    }
    else {
      head = tmp;
    }

    return head;
  }
};