
/*

Write a function that takes in a BST and a positive integer k
and returns the kth largest integer contained in the BST.

*/

using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

void reverse_inorder(BST *tree, int k, int *count, int *kth) {
    if (tree == nullptr || *count >= k)
        return;
    reverse_inorder(tree->right, k, count, kth);
    if (*count < k) {
      *kth = tree->value;
      (*count)++;
      reverse_inorder(tree->left, k, count, kth);
    }
}

// O(h + k) time
int findKthLargestValueInBst(BST *tree, int k) {
    int count = 0, kth = -1;
    reverse_inorder(tree, k, &count, &kth);
    return kth;
}


