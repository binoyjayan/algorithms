/*

Given an non-empty array of integers representing the pre-order
traversal of a BST, write a function that creates the relevant
BST and returns its root node.

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

BST *reconstructBst(vector<int> &preOrderTraversalValues,
                                        int min, int max, int &rootidx) {
    if (rootidx == preOrderTraversalValues.size())
        return nullptr;

    int rootValue = preOrderTraversalValues[rootidx];
    // A node doesn't belong here if:
    if (rootValue < min || rootValue >= max)
        return nullptr;

    rootidx++;

    BST *bst = new BST(rootValue);
    // Now, the upper bound of left subtree is 'rootValue'
    bst->left = reconstructBst(preOrderTraversalValues, min, rootValue, rootidx);
    // The lower bound of right subtree is 'rootValue'
    bst->right = reconstructBst(preOrderTraversalValues, rootValue, max, rootidx);
    return bst;
}

BST *reconstructBst(vector<int> preOrderTraversalValues) {
    int rootidx = 0;
    return reconstructBst(preOrderTraversalValues, INT_MIN, INT_MAX, rootidx);
}


