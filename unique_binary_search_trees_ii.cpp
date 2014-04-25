class Solution {
public:
  void generate_trees(int start,
      int end,
      vector<TreeNode*> &trees) {
    if (start > end) {
      trees.push_back(NULL);
    }
    else {
      int i;
      int j;
      int k;

      for (i = start; i <= end; ++i) {
        vector<TreeNode*> left_sub_trees;
        vector<TreeNode*> right_sub_trees;

        generate_trees(start, i - 1, left_sub_trees);
        generate_trees(i + 1, end, right_sub_trees);

        for (j = 0; j < left_sub_trees.size(); ++j) {
          for (k = 0; k < right_sub_trees.size(); ++k) {
            TreeNode *node = new TreeNode(i);

            node->left = left_sub_trees[j];
            node->right = right_sub_trees[k];
            trees.push_back(node);
          }
        }
      }
    }
  }

  vector<TreeNode *> generateTrees(int n) {
    vector<TreeNode*> trees;

    generate_trees(1, n, trees);

    return trees;
  }
};