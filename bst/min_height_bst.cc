
/*

Write a function that takes in a non0empty sorted array
of distinct integers, constructs a BST from the integers,
and returns the root of the BST.

The function should minimize the height of the BST created.

*/

using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};

BST *minHeightBst(vector<int> a, BST *tree, int start, int end) {
    if (start > end)
        return nullptr;
    int mid = start + (end - start) / 2;
    int value = a[mid];
    if (tree == nullptr) {
        tree = new BST(value);
    } else {
      tree->insert(value);
    }
    minHeightBst(a, tree, start, mid - 1);
    minHeightBst(a, tree, mid + 1, end);
    return tree;
}


BST *minHeightBst(vector<int> a) {
    return minHeightBst(a, nullptr, 0, a.size() - 1);
}

