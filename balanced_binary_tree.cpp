class Solution {
public:
  bool is_balanced(TreeNode *root, int &height) {
    if (NULL == root) {
      height = 0;

      return true;
    }

    int left_height;
    int right_height;
    bool is_left_balanced = is_balanced(root->left, left_height);
    bool is_right_balanced = is_balanced(root->right, right_height);

    height = 1 + max(left_height, right_height);

    if (is_left_balanced && is_right_balanced) {
      return (abs(left_height - right_height) <= 1) ? true : false;
    }
    else {
      return false;
    }
  }

  bool isBalanced(TreeNode *root) {
    int height;

    return is_balanced(root, height);
  }
};