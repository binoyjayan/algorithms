
/*

Write a function that takes in a Binary Tree and returns
a list of its branch sums ordered from leftmost branch sum
to the right to rightmost branch sum.

A branch sum is the sum of all values in a Binary Tree branch.

*/

using namespace std;

// This is the class of the input root. Do not edit it.
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

void inorder(BinaryTree *tree, vector<int> &sums, int sum) {
    if (tree == nullptr)
      return;
  if (!tree->left && !tree->right)
        sums.push_back(sum + tree->value);
    inorder(tree->left, sums, sum + tree->value);
  inorder(tree->right, sums, sum + tree->value);
}
vector<int> branchSums(BinaryTree *root) {
    vector<int> sums;
    inorder(root, sums, 0);
  return sums;
}


