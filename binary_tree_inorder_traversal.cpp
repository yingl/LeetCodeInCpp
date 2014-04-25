class Solution {
public:
  void inorder_traversal(TreeNode *root, vector<int> &result) {
    if (NULL == root) {
      return;
    }

    inorder_traversal(root->left, result);
    result.push_back(root->val);
    inorder_traversal(root->right, result);
  }

  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;

    inorder_traversal(root, result);

    return result;
  }
};