
/*

Write a BST class for a Binary Search Tree. The class should support:

Inserting values with the insert method

Removing values with remove method that removes only the
first instance of a given value.

Searching for values with the contains method.

*/

#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
public:
  int value;
  BST *left;
  BST *right;
  BST(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
  }

  BST &insert(int val) {
    if (val < value) {
          if (left == nullptr) {
                left = new BST(val);
            } else {
                left->insert(val);
            }
        } else { // Do not check if (val > value)
            if (right == nullptr) {
                right = new BST(val);
            } else {
                right->insert(val);
            }
        }
    return *this;
  }

  bool contains(int val) {
    // Write your code here.
        if (val < value) {
          if (left == nullptr)
                return false;
      else
                return left->contains(val);
        } else if (val > value) {
            if (right == nullptr)
                return false;
      else
                return right->contains(val);
        }
        return true;
  }

  BST &remove(int val, BST *parent = nullptr) {
    if (val < value) {
          if (left)
                left->remove(val, this);
        } else if (val > value) {
            if (right)
                right->remove(val, this);
        } else {
            // If current node has two children
            if (left != nullptr && right != nullptr) {
                // Replace current node with the min value
                // in the right sub-tree
                value = right->get_min_value();
                right->remove(value, this);
            } else if (parent == nullptr) { // current node is root
                if (left != nullptr) { // root only has left branch
                    value = left->value;
                    right = left->right;
                    left = left->left;
        } else if (right != nullptr) { // root only has right branch
                    value = right->value;
                    left = right->left;
                    right = right->right;
        } // else, do not do anything for a single node tree
      } else if (parent->left == this) {
                // current node is the left node of parent
                parent->left = left != nullptr? left : right;
      } else if (parent->right == this) {
                // current node is the right node of parent
                parent->right = left != nullptr? left: right;
      }
        }
    return *this;
  }
    int get_min_value() {
        if (left == nullptr) {
            return value;
        } else {
            return left->get_min_value();
        }            
    }
};


