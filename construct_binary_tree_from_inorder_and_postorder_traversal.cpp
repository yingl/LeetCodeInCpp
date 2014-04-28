class Solution {
public:
  // 参考construct_binary_tree_from_preorder_and_inorder_traversal.cpp
  TreeNode* build_tree(vector<int> &inorder,
      int in_start,
      int in_end,
      vector<int> &postorder,
      int post_start,
      int post_end) {
    if (post_start > post_end) {
      return NULL;
    }
    else if (post_start == post_end) {
      return new TreeNode(postorder[post_start]);
    }

    int i = 0;

    for ( ; (in_start + i) <= in_end; ++i) {
      if (inorder[in_start + i] == postorder[post_end]) {
        break;
      }
    }

    TreeNode *root = new TreeNode(postorder[post_end]);

    root->left = build_tree(inorder,
        in_start,
        in_end + (i - 1),
        postorder,
        post_start,
        post_start + (i - 1));
    root->right = build_tree(inorder,
        in_start + (i + 1),
        in_end,
        postorder,
        post_start + i,
        post_end - 1);

    return root;
  }

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
      return build_tree(inorder,
          0,
          inorder.size() - 1,
          postorder,
          0,
          postorder.size() - 1); 
  }
};