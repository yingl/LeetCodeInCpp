class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (NULL == head) {
      return false;
    }

    ListNode *curr = head;
    ListNode *next = head->next;

    while (true) {
      curr = curr->next;

      int steps = 0;

      while ((next != NULL) && (steps < 2)) {
        next = next->next;
        ++steps;
      }

      if (NULL == next) {
        return false;
      }

      if (curr == next) {
        return true;
      }
    }
  }
};