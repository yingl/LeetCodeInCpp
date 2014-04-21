class Solution {
public:
  void insert_node(ListNode *&head, ListNode *&tail, ListNode *node) {
    if (NULL == head) {
      head = node;
    }
    else {
      tail->next = node;
    }

    tail = node;
  }

  ListNode *deleteDuplicates(ListNode *head) {
    if (NULL == head) {
      return NULL;
    }
    
    ListNode *new_head = NULL;
    ListNode *new_tail = NULL;
    ListNode *node = head->next;
    int count = 1;

    while (node != NULL) {
      if (head->val != node->val) {
        if (1 == count) {
          insert_node(new_head, new_tail, head);
        }

        head = node;
        count = 1;
      }
      else {
        ++count;
      }

      node = node->next;
    }

    if ((head != NULL) && (1 == count)) {
      insert_node(new_head, new_tail, head);
    }

    if (new_tail != NULL) {
      new_tail->next = NULL;
    }

    return new_head;
  }
};