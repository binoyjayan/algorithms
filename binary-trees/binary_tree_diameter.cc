
/*

Write a function that takes in a binary tree and returns its diameter.
The diameter of a binary tree is the length of its longest path, even
if that does not pass through the root node.

*/

using namespace std;

// This is an input class. Do not edit.
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

struct TreeInfo {
  int diameter, height;    
};

TreeInfo get_tree_info(BinaryTree *tree) {
    if (tree == nullptr) {
        return TreeInfo{0, 0};
    }
    TreeInfo left = get_tree_info(tree->left);
    TreeInfo right = get_tree_info(tree->right);
    
    int max_path = left.height + right.height;
    int max_dia = max(left.diameter, right.diameter);
    int curr_dia = max(max_path, max_dia);
    int curr_height = 1 + max(left.height , right.height);
    return TreeInfo{curr_dia, curr_height};
}

int binaryTreeDiameter(BinaryTree *tree) {
  return get_tree_info(tree).diameter;
}


