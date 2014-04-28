class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    if (NULL == head) {
      return NULL;
    }

    ListNode *curr = head;
    ListNode *next = head;
    ListNode *prev = NULL;

    while (next != NULL) {
      // 通过走一步／两步找到中间节点
      next = next->next;

      if (NULL == next) {
        break;
      }

      next = next->next;
      prev = curr;
      curr = curr->next;
    }

    if (NULL == curr) {
      return new TreeNode(head->val);
    }
    else {
      TreeNode *root = new TreeNode(curr->val);

      // 把链表拆成两端递归
      if (prev != NULL) {
        prev->next = NULL;
        root->left = sortedListToBST(head);
      }

      root->right = sortedListToBST(curr->next);

      return root;
    }
  }
};