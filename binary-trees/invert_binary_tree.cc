
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

bool isMirror(TreeNode* left, TreeNode* right) {
    if (!left || !right)
        return left == right;
    return (left->val == right->val) 
        && isMirror(left->left, right->right)
        && isMirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root)
        return true;
    return isMirror(root->left, root->right);    
}
