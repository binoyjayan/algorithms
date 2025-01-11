
#include <queue>
#include <string>

/*
 * TST : 3-way Trie
 *
 *  Each node has a character, three links and a value.
 */

template <typename T>
class TST {
    struct Node {
        char c;
        T* value;
        Node *left, *mid, *right;
        Node() {
            left = mid = right = nullptr;
        }
    };
    Node *root;
    // Change value associated with key in the sub-trie rooted at 'x'
    Node* put(Node *x, std::string key, T* value, int d) {
        int c = (int) key[d];
        if (x == nullptr) {
            x = new Node();
            x->c = c;
        }
        if (c < x->c)
            x->left = put(x->left, key, value, d);
        else if (c > x->c)
            x->right = put(x->right, key, value, d);
        else if (d < key.length() - 1)
            x->mid = put(x->mid, key, value, d + 1);
        else
            x->value = value;
        return x;
    }
    // Return node associated with key in teh sub-trie rooted at 'x'
    Node* get(Node *x, std::string key, int d) {
        if (x == nullptr)
            return nullptr;
        int c = (int) key[d];
        if (c < x->c)
            return get(x->left, key, d);
        else if (c > x->c)
            return get(x->right, key, d);
        else if (d < key.length() - 1)
            return get(x->mid, key, d + 1);
        else
            return x;
    }
public:
    TST() {
        root = new Node();
    }
    ~TST() {
        delete_nodes(root);
    }
    void delete_nodes(Node *node) {
        if (node == nullptr)
            return;
        if (node->value) {
            delete node->value;
            node->value = nullptr;
        }
        if (node->left) {
            delete node->left;
        }
        if (node->mid) {
            delete node->mid;
        }
        if (node->right) {
            delete node->right;
        }
    }
    T* get(std::string key) {
        Node *x = get(root, key, 0);
        if (x == nullptr)
            return nullptr;
        return x->value;
    }
    void put(std::string key, T* value) {
        root = put(root, key, value, 0);
    }
};
