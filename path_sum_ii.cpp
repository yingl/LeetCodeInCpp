class Solution {
public:
  void path_sum(TreeNode *root,
      int sum,
      vector<int> &path,
      vector<vector<int> > &pathes) {
    if (NULL == root) {
      return;
    }
    else {
      if ((NULL == root->left) && (NULL == root->right)) {
        if (root->val == sum) {
          path.push_back(sum);
          pathes.push_back(path);
          path.pop_back();
        }
      }
      else {
        path.push_back(root->val);

        if (root->left != NULL) {
          path_sum(root->left, sum - root->val, path, pathes);
        }

        if (root->right != NULL) {
          path_sum(root->right, sum - root->val, path, pathes);
        }

        path.pop_back();
      }
    }
  }

  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > pathes;
    vector<int> path;

    path_sum(root, sum, path, pathes);

    return pathes;
  }
};