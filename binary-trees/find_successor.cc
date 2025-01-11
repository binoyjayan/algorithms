
/*

Write a function that takes in a binary tree as well as a node
contained in that tree and returns the given node's successor.

A nodes successor is the node to be visited immediately after the
given node when traversing the tree using in-order traversal.

*/

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;
  BinaryTree *parent = nullptr;

  BinaryTree(int value) { this->value = value; }
};

BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node, BinaryTree **prev) {
    if(tree == nullptr) {
        return nullptr;
    }
    BinaryTree *successor;
    // Check if we found successor in left subtree
    if ((successor = findSuccessor(tree->left, node, prev)))
        return successor;
    // Base case: if 'prev' == 'node', the the current node is the successor
    if (*prev == node) {
        return tree;
    }
    // save the prev as the current node
    *prev = tree;
    return findSuccessor(tree->right, node, prev);
}

BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
    BinaryTree *prev = nullptr;
    return findSuccessor(tree, node, &prev);
}


