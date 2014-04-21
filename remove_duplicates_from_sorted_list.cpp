class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (NULL == head) {
      return NULL;
    }

    ListNode *curr = head;
    ListNode *next = head->next;

    while (next != NULL) {
      if (curr->val != next->val) {
        curr->next = next;
        curr = next;
      }

      next = next->next;
    }

    curr->next = NULL;

    return head;
  }
};