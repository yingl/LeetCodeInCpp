class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *list_1 = head;
    ListNode *list_2 = head;
    ListNode *prev = NULL;

    // 请仔细阅读题目
    for (int i = 1; i < n; ++i) {
      list_2 = list_2->next;
    }

    while (true) {
      // list_2现在位于最后一个元素
      if (NULL == list_2->next) {
        break;
      }

      prev = list_1;  // 记住前一个元素的位置
      list_1 = list_1->next;
      list_2 = list_2->next;
    }

    // 执行删除操作
    if (prev != NULL) {
      prev->next = list_1->next;

      return head;
    }
    else {
      // 如果prev是NULL说明head就是要删除的元素
      return list_1->next;
    }
  }
};