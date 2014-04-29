class Solution {
public:
  int max_path_sum(TreeNode *root, int &max_sum) {
    if ((NULL == root->left) && (NULL == root->right)) {
      if (root->val > max_sum) {
        max_sum = root->val;
      }

      return root->val;
    }
    else {
      int tmp = root->val;
      int left_max = INT_MIN;
      int right_max = INT_MIN;

      if (root->left != NULL) {
        left_max = max_path_sum(root->left, max_sum);
      }

      if (root->right != NULL) {
        right_max = max_path_sum(root->right, max_sum);
      }

      if (left_max > 0) {
        tmp += left_max;
        left_max += root->val;
      }

      if (right_max > 0) {
        tmp += right_max;
        right_max += root->val;
      }

      if (tmp > max_sum) {
        max_sum = tmp;
      }

      return max(root->val, max(left_max, right_max));
    }
  }
  int maxPathSum(TreeNode *root) {
    int max_sum = INT_MIN;

    max_path_sum(root, max_sum);

    return max_sum; 
  }
};