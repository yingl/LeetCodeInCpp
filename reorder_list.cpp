class Solution {
public:
  void reorderList(ListNode *head) {
    if ((NULL == head) || (NULL == head->next)) {
      return;
    }

    int len = 0;    // 计算链表长度
    ListNode *node = head;

    while (node != NULL) {
      ++len;
      node = node->next;
    }

    // 把链表从当中拆分成两个链表
    int cut_point = (len + 1) / 2;
    int i = 1;
    ListNode *head_1 = head;
    ListNode *head_2 = NULL;

    node = head_1;

    while (true) {
      if (i == cut_point) {
        head_2 = node->next;
        node->next = NULL;

        break;
      }
      else {
        node = node->next;
        ++i;
      }
    }

    head_2 = reverse_list(head_2);

    // 合并head_1和head_2
    while (head_2 != NULL) {
      node = head_1->next;
      head_1->next = head_2;
      head_2 = head_2->next;
      head_1->next->next = node;
      head_1 = node;

      if (NULL == head_1) {
        break;
      }
    }
  }

protected:
  ListNode* reverse_list(ListNode* head) {
    ListNode *new_head = NULL;
    ListNode *new_tail = NULL;

    while (head != NULL) {
      if (NULL == new_head) {
        new_head = head;
        new_tail = head;
        head = head->next;
        new_tail->next = NULL;
      }
      else {
        ListNode *node = head->next;

        head->next = new_head;
        new_head = head;
        head = node;
      }
    }

    return new_head;
  }
};