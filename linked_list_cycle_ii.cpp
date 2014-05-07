class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (NULL == head) {
      return false;
    }

    ListNode *curr = head;
    ListNode *next = head->next;
    ListNode *new_head = head->next;

    while (true) {
      curr = curr->next;

      int steps = 0;

      while ((next != NULL) && (steps < 2)) {
        next = next->next;
        ++steps;
      }

      if (NULL == next) {
        return NULL;
      }

      if (curr == next) {
        break;
      }
    }

    next = next->next;

    // new_head的位置等于head往前走圈的长度
    while (curr != next) {
      new_head = new_head->next;
      next = next->next;
    }

    // head和new_head的重合点就是
    while (head != new_head) {
      head = head->next;
      new_head = new_head->next;
    }

    return head;
  }
};