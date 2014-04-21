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

  ListNode *partition(ListNode *head, int x) {
    if (NULL == head) {
      return NULL;
    }

    ListNode *lt_head = NULL;
    ListNode *lt_tail = NULL;
    ListNode *ge_head = NULL;
    ListNode *ge_tail = NULL;

    while (head != NULL) {
      if (head->val < x) {
        insert_node(lt_head, lt_tail, head);
      }
      else {
        insert_node(ge_head, ge_tail, head);
      }

      head = head->next;
    }

    if (ge_tail != NULL) {
      ge_tail->next = NULL;
    }

    if (NULL == lt_head) {
      return ge_head;
    }
    else {
      lt_tail->next = ge_head;

      return lt_head;
    }
  }
};