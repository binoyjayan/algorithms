
/*

Write a function that inverts a binary tree.
As in a mirror image.

*/

#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree *tree) {
    if (tree->left != nullptr) {
        invertBinaryTree(tree->left);
  }
    if (tree->right != nullptr) {
        invertBinaryTree(tree->right);
  }
    std::swap(tree->left, tree->right);
}


