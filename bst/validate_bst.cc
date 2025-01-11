
/*

Write a function that takes in a potentially invalid BST 
and returns a boolean representing whether the BST is valid.

A BST is valid if and only if all of its nodes are valid BST nodes.

*/

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

bool validateBst(BST *tree, int min = INT_MIN, int max = INT_MAX) {
    if (tree->value < min || tree->value >= max)
        return false;
    if (tree->left != nullptr && !validateBst(tree->left, min, tree->value)) {
        return false;
    }
    if (tree->right != nullptr && !validateBst(tree->right, tree->value, max)) {
        return false;
    }
    return true;
}



