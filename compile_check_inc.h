#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

 struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x, ListNode *_next = NULL) : val(x), next(_next) {}
 };

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x, TreeNode *_left = NULL, TreeNode *_right = NULL) : 
      val(x), left(_left), right(_right) {}
 };

struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode*> neighbors;
  UndirectedGraphNode(int x) : label(x) {}
};

struct RandomListNode {
  int label;
  RandomListNode *next;
  RandomListNode *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};