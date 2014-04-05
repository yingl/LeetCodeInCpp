class Solution {
public:
  ListNode* merge_two_lists(ListNode *list_1, ListNode *list_2) {
    ListNode *head = NULL;
    ListNode *tail = NULL;
    ListNode *tmp = NULL;

    while ((list_1 != NULL) && (list_2 != NULL)) {
      if (list_1->val < list_2->val) {
        tmp = list_1;
        list_1 = list_1->next;
      }
      else {
        tmp = list_2;
        list_2 = list_2->next;
      }

      if (NULL == head) {
        head = tmp;
        tail = tmp;
      }
      else {
        tail->next = tmp;
        tail = tmp;
      }
    }

    tmp = (NULL == list_1) ? list_2 : list_1;

    if (head != NULL) {
      tail->next = tmp;

      return head;
    }
    else {
      return tmp;
    }
  }

  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (0 == lists.size()) {
      return NULL;
    }

    ListNode *head = lists[0];

    for (int i = 1; i < lists.size(); ++i) {
      head = merge_two_lists(head, lists[i]);
    }

    return head;
  }
};