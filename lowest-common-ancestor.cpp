#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNodeCollection {
  TreeNode* root;
  TreeNode* p;
  TreeNode* q;
};

TreeNodeCollection createTree(vector<int> input);
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

int main(int argc, char const* argv[]) {
  vector<int> input1 = {6, 2, 8, 0, 4, 7, 9, NULL, NULL, 3, 5};
  vector<int> input2 = {6, 2, 8, 0, 4, 7, 9, NULL, NULL, 3, 5};
  vector<int> input3 = {2, 1};
  vector<int> input4 = {1, 2, 3, 4, 5};

  int p1 = 2, q1 = 8;
  int p2 = 2, q2 = 4;
  int p3 = 2, q3 = 1;
  int p4 = 5, q4 = 3;

  TreeNodeCollection tc1 = createTree(input1, p1, q1);
  TreeNodeCollection tc2 = createTree(input2, p2, q2);
  TreeNodeCollection tc3 = createTree(input3, p3, q3);
  TreeNodeCollection tc4 = createTree(input4, p4, q4);

  return 0;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
}

// Create a tree given a vector of input elements,
// integers p and q.
// Returns root of tree, pointer to p node,
// pointer to q node encapsulated in a struct
// of type TreeNodeCollection
TreeNodeCollection createTree(vector<int> input, int p, int q) {
  queue<TreeNode*> nodes;
  TreeNode *node, *parent, *root;
  TreeNodeCollection tc;
  tc.root = nullptr;
  tc.p = nullptr;
  tc.q = nullptr;

  if (input.size() == 0) {
    return tc;
  }

  // First element of input vector will always be the root node
  root = new TreeNode(input[0]);

  if (input.size() == 1) {
    tc.root = root;
    tc;
  }

  parent = root;
  bool isLeftFilled = false;

  for (int i = 1; i < input.size(); i++) {
    // cout << input[i] << ": ";
    if (input[i] != NULL) {
      node = new TreeNode(input[i]);
      // if node value is same as p
      if (input[i] == p)
        tc.p = node;
      // if node value is same as q
      if (input[i] == q)
        tc.q = node;
      // add node to queue
      nodes.push(node);
      if (!isLeftFilled) {
        parent->left = node;
        // cout << "adding " << node->val << " to left of " << parent->val << endl;
        isLeftFilled = true;
      } else {
        parent->right = node;
        // cout << "adding " << node->val << " to right of " << parent->val << endl;
        parent = nodes.front();
        // cout << "new parent: " << parent->val << endl;
        nodes.pop();
        isLeftFilled = false;
      }
      // cout << "adding " << node->val << " to " << parent->val << endl;
    } else {
      if (!isLeftFilled) {
        parent->left = nullptr;
        isLeftFilled = true;
        // cout << "adding null to left of " << parent->val << endl;
      } else {
        parent->right = nullptr;
        // cout << "adding null to right of " << parent->val << endl;
        parent = nodes.front();
        // cout << "new parent: " << parent->val << endl;
        nodes.pop();
        isLeftFilled = false;
      }
    }
  }

  tc.root = root;

  return tc;
}
