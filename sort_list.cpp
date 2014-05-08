class Solution {
public:
  ListNode *sortList(ListNode *head) {
    return split_and_merge(head);
  }

protected:
  ListNode* split_and_merge(ListNode* head) {
    if ((NULL == head) || (NULL == head->next)) {
      return head;
    }

    ListNode *node_1 = head;
    ListNode *node_2 = head;

    while ((node_2->next != NULL) && (node_2->next->next != NULL)) {
      node_1 = node_1->next;
      node_2 = node_2->next->next;
    }

    ListNode *head_1 = head;
    ListNode *head_2 = node_1->next;

    node_1->next = NULL;

    head_1 = split_and_merge(head_1);
    head_2 = split_and_merge(head_2);

    return merge(head_1, head_2);
  }

  ListNode* merge(ListNode *node_1, ListNode* node_2) {
    ListNode *head = NULL;
    ListNode *tail = NULL;
    ListNode *node = NULL;

    while ((node_1 != NULL) && (node_2 != NULL)) {
      if (node_1->val > node_2->val) {
        node = node_2;
        node_2 = node_2->next;
      }
      else {
        node = node_1;
        node_1 = node_1->next;
      }

      if (NULL == head) {
        head = node;
      }
      else {
        tail->next = node;
      }

      tail = node;
      tail->next = NULL;
    }

    node = (node_1 != NULL) ? node_1 : node_2;

    if (tail != NULL) {
      tail->next = node;
    }

    return (head != NULL) ? head : node;
  }
};