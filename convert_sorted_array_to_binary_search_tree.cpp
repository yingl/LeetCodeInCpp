class Solution {
public:
  TreeNode* convert_sorted_array_to_bst(vector<int> &num,
      int min,
      int max) {
    if (min > max) {
      return NULL;
    }
    else {
      int mid = (min + max) / 2;
      TreeNode *root = new TreeNode(num[mid]);

      root->left = convert_sorted_array_to_bst(num, min, mid - 1);
      root->right = convert_sorted_array_to_bst(num, mid + 1, max);

      return root;
    }
  }

  TreeNode *sortedArrayToBST(vector<int> &num) {
    return convert_sorted_array_to_bst(num, 0, num.size() - 1);
  }
};