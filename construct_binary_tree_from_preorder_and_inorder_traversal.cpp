class Solution {
public:
  TreeNode* build_tree(vector<int> &preorder,
      int pre_start,
      int pre_end,
      vector<int> &inorder,
      int in_start,
      int in_end) {
    if (pre_start > pre_end) {
      return NULL;
    }
    else if (pre_start == pre_end) {
      return new TreeNode(preorder[pre_start]);
    }

    int i = 0;

    // 找到中间节点
    for ( ; (in_start + i) <= in_end; ++i) {
      if (preorder[pre_start] == inorder[in_start + i]) {
        break;
      }
    }

    // 确定根节点
    TreeNode *root = new TreeNode(preorder[pre_start]);

    root->left = build_tree(preorder,
        pre_start + 1,
        pre_start + i,
        inorder,
        in_start,
        in_start + (i - 1));
    root->right = build_tree(preorder,
        pre_start + (i + 1),
        pre_end,
        inorder,
        in_start + (i + 1),
        in_end);

    return root;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return build_tree(preorder,
        0,
        preorder.size() - 1,
        inorder,
        0,
        inorder.size() - 1);
  }
};