#include <iostream>
#include <climits>
using namespace std;


/*
Write a function that takes a binary search tree and a target integer
and returns the closest value to that target contained in the BST.
*/
class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

BST::BST(int val) {
  value = val;
  left = nullptr;
  right = nullptr;
}

void inorder(BST *tree, int target, int *closest) {
    if (tree == nullptr)
        return;
    if (tree->left) {
      return inorder(tree->left, target, closest);
    }
    int d1 = abs(target - tree->value);
    int d2 = abs(*closest - tree->value);
    cout << "val:" << tree->value << ",d1:" << d1 << ",d2:" << d2 << endl;
    if (d1 < d2) {
        *closest = tree->value;
    }
    if (tree->right) {
        return inorder(tree->right, target, closest);
    }
}

int findClosestValueInBst(BST *tree, int target) {
    int closest = tree->value;
    inorder(tree, target, &closest);
    return closest;
}

int main() {
    BST *root = new BST(10);
    root->left = new BST(5);
    root->left->left = new BST(2);
    root->left->left->left = new BST(1);
    root->left->right = new BST(5);
    root->right = new BST(15);
    root->right->left = new BST(13);
    root->right->left->right = new BST(14);
    root->right->right = new BST(22);
    int expected = 13;
    int actual = findClosestValueInBst(root, 12);
}


