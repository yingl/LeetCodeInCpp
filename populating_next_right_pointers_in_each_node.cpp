class Solution {
public:
  void connect(TreeLinkNode *root) {
    if (NULL == root) {
      return;
    }

    if (root->left != NULL) {
      root->left->next = root->right;
    }

    if (root->right != NULL) {
      root->right->next = (root->next != NULL) ? root->next->left : NULL;
    }

    connect(root->left);
    connect(root->right);
  }
};