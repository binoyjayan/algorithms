
/*

Write a function that returns true if a given tree is height balanced.
*/

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};


struct TreeInfo {
  int height;
    bool balanced;
};

TreeInfo checkHeightBalance(BinaryTree *tree) {
    if (tree == nullptr) {
        return TreeInfo{0, true};
  }
    TreeInfo left = checkHeightBalance(tree->left);
    if (!left.balanced)
        return left;
    TreeInfo right = checkHeightBalance(tree->right);
    if (!right.balanced)
        return right;
    TreeInfo ti;
    ti.height = max(left.height, right.height) + 1;
    if (abs(left.height - right.height) <= 1)
       ti.balanced = left.balanced && right.balanced;
    else
        ti.balanced = false;
    return ti;
}

bool heightBalancedBinaryTree(BinaryTree *tree) {
   return checkHeightBalance(tree).balanced;
}

