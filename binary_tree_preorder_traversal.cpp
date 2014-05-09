class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode*> s;

    if (NULL == root) {
      return result;
    }

    s.push(NULL);

    while (root != NULL) {
      while ((root != NULL) || (s.top() != NULL)) {
        while (root != NULL) {
          result.push_back(root->val);
          s.push(root);
          root = root->left;
        }

        root = s.top();
        s.pop();
        root = root->right;
      }
    }

    return result;
  }
};