class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode*> s;
    map<TreeNode*, bool> right_visited;

    s.push(NULL);

    while ((root != NULL) || (s.top() != NULL)) {
      while (root != NULL) {
        s.push(root);
        root = root->left;
      }

      root = s.top();

      if (NULL == root) {
        break;
      }
      else {
        while ((right_visited[root]) && (root != NULL)) {
          result.push_back(root->val);
          s.pop();
          root = s.top();
        }

        right_visited[root] = true;

        if (root != NULL) {
          root = root->right;
        }
      }
    }

    return result;
  }
};