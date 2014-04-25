class Solution {
public:
  //  最简单的例子
  //  3
  //   \
  //    2
  //     \
  //      1
  // 把1，3交换就可以了。
  // 1. in_order(3->left)
  // 2. _parent = 3
  // 3. 3->right = 2, inorder(2)
  // 4. inorder(2->left)
  // 5. root = 2, 3 > 2 => _first = 3, _second = 2, _parent = 2
  // 6. in_order(2->right)
  // 7. in_order(1->left)
  // 8. root = 1, 2 > 1 => _second = 1)
  void in_order(TreeNode *root) {
    if (NULL == root) {
      return;
    }
    else {
      // 先推到最左边的节点
      in_order(root->left);

      if (NULL == _parent) {
        _parent = root;
      }
      else {
        // 因为是中序遍历，_parent在root左面，这两个节可能需要交换。
        if (_parent->val > root->val) {
          if (NULL == _first) {
            _first = _parent;
          }

          _second = root;
        }

        // _parent提升到当前层
        _parent = root;
      }

      in_order(root->right);
    }
  }

  void recoverTree(TreeNode *root) {
    _parent = NULL;
    _first = NULL;
    _second = NULL;

    in_order(root);

    swap(_first->val, _second->val);
  }

protected:
  TreeNode *_parent;  // _first和_second的最近公共父节点
  TreeNode *_first;
  TreeNode *_second;
};