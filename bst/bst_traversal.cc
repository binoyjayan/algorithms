
/*

Write three functions that takes in a BST and and empty
array, traverse the BST, add its nodes' values to the
input array and return that array. The three functions
should traverse that BST using the in-order,pre-order
and post-order traversal techniqiues.
*/

#include <vector>
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
};

void inOrderTraverse(BST *tree, vector<int> &array) {
    if (tree->left) inOrderTraverse(tree->left, array);
  array.push_back(tree->value);
    if (tree->right) inOrderTraverse(tree->right, array);
}

void preOrderTraverse(BST *tree, vector<int> &array) {
    array.push_back(tree->value);
    if (tree->left) preOrderTraverse(tree->left, array);
    if (tree->right) preOrderTraverse(tree->right, array);
}

void postOrderTraverse(BST *tree, vector<int> &array) {
    if (tree->left) postOrderTraverse(tree->left, array);
    if (tree->right) postOrderTraverse(tree->right, array);
    array.push_back(tree->value);
}


