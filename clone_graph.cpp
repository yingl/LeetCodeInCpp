class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
     map<UndirectedGraphNode*, UndirectedGraphNode*> cloned;

     return _clone_graph(node, cloned);
  }

protected:
  UndirectedGraphNode* _clone_graph(UndirectedGraphNode *node,
      map<UndirectedGraphNode*, UndirectedGraphNode*> &cloned) {
    if (NULL == node) {
      return NULL;
    }
    else if (cloned.find(node) != cloned.end()) {
      return cloned[node];
    }

    UndirectedGraphNode *cnode = new UndirectedGraphNode(node->label);

    cloned[node] = cnode;

    for (int i = 0; i < (node->neighbors).size(); ++i) {
      (cnode->neighbors).push_back(_clone_graph((node->neighbors)[i], cloned));
    }

    return cnode;
  }
};