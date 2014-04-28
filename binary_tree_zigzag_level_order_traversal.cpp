class Solution {
public:
  vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> > result;
    vector<TreeNode*> levels[2];
    int curr = 0;
    int next = 1;
    bool flag = false;

    if (root != NULL) {
      levels[curr].push_back(root);
    }

    while (!levels[curr].empty()) {
      vector<int> level;
      int curr_size = levels[curr].size();

      for (int i = 0; i < curr_size; ++i) {
        level.push_back(levels[curr][i]->val);

        if (levels[curr][i]->left != NULL) {
          levels[next].push_back(levels[curr][i]->left);
        }

        if (levels[curr][i]->right != NULL) {
          levels[next].push_back(levels[curr][i]->right);
        }
      }

      if (flag) {
        reverse(level.begin(), level.end());
      }

      result.push_back(level);
      swap(curr, next);
      levels[next].clear();
      flag = !flag;
    }

    return result;
  }
};