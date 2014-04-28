class Solution {
public:
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > result;
    queue<TreeNode*> queues[2];
    int curr_queue = 0;
    int next_queue = 1;

    if (NULL == root) {
      return result;
    }

    queues[curr_queue].push(root);
    
    while (!queues[curr_queue].empty()) {
      vector<int> level;

      while (!queues[curr_queue].empty()) {
        TreeNode *node = queues[curr_queue].front();

        queues[curr_queue].pop();

        if (node->left != NULL) {
          queues[next_queue].push(node->left);
        }

        if (node->right != NULL) {
          queues[next_queue].push(node->right);
        }

        level.push_back(node->val);
      }

      result.push_back(level);
      swap(curr_queue, next_queue);
    }

    reverse(result.begin(), result.end());
    
    return result;
  }
};