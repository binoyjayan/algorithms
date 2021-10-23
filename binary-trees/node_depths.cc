
/*

The distance between a node in a binary tree and the tree's root
is called the node's depth.

Write a function that takes in a binary tree and return the sum of
its nodes' depths.
*/

using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

void find_depth(BinaryTree *tree, int level, int *depth) {
  if (tree->left) {
        find_depth(tree->left, level + 1, depth);
  }
    *depth += level;
  if (tree->right) {
    find_depth(tree->right, level + 1, depth);
  }
}

int nodeDepths(BinaryTree *root) {
  int depth = 0;
  find_depth(root, 0, &depth);
    return depth;
}

