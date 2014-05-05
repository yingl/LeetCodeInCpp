class Solution {
public:
  void sum_of_numbers(TreeNode *root, int &sum) {
    if (root != NULL) {
      if ((NULL == root->left) && (NULL == root->right)) {
        sum += root->val;
      }
      else {
        if (root->left != NULL) {
          root->left->val += root->val * 10;
          sum_of_numbers(root->left, sum);
        }

        if (root->right != NULL) {
          root->right->val += root->val * 10;
          sum_of_numbers(root->right, sum);
        }
      }
    }
  }

  int sumNumbers(TreeNode *root) {
    int sum = 0;

    sum_of_numbers(root, sum);

    return sum;
  }
};