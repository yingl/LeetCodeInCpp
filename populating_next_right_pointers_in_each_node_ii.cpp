class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (NULL == root) {
      return;
    }

    TreeLinkNode *node = root->next;
    TreeLinkNode *next = NULL;

    while (node != NULL) {
      if ((node->left != NULL) || (node->right != NULL)) {
        next = (node->left != NULL) ? node->left : node->right;
        break;
      }
      else {
        node = node->next;
      }
    }

    if (root->left != NULL) {
      root->left->next = (root->right != NULL) ? root->right : next;
    }

    if (root->right != NULL) {
      root->right->next = next;
    }

    // 必须先右子树，不然左子树最右节点的next会不知道指向哪里。
    connect(root->right);
    connect(root->left);
  }
};