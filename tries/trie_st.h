#include <queue>
#include <string>

/*
 * TrieST : Trie Symbol Table
 *
 * Data structure composed of nodes that contains links that are
 * either null or references to other nodes. Each node is pointed
 * to by just one other node, which is called its parent.
 * (except for root node that has no nodes pointing to it).
 *
 * Every node has R links, one for each possible character
 * Characters are implicitly stored in the data structure
 *
 * Keys in the tries are implicitly represented by paths from the root
 * that end at nodes with non-null values.
 *
 * e.g. Consider the key 'sea' for a english alphabet character set (R = 26)
 * - root node: 19th link -> points to a trie for all keys that start with 's'
 * - node at link 19: 5th link -> points to a trie for keys that start with 'se'
 * - node at link 5: 1st link -> Has a value of 'val' or what is indented.
 *
 * Neither the key 'sea' nor the characters that make up the key are stored
 * in the trie data structure. Since the parameter R plays a critical role,
 * the trie for an R-character alphabet is called an R-way trie.
 */

template <typename T>
class TrieST {
    const static int R = 256;
    struct Node {
        T* value;
        Node *next[R];
        Node() {
            for (int i = 0; i < R; i++) {
                next[i] = nullptr;
            }
        }
    };
    Node *root;
    // Change value associated with key in the sub-trie rooted at 'x'
    Node* put(Node *x, std::string key, T* value, int d) {
        if (x == nullptr)
            x = new Node();
        if (d == key.length()) {
            x->value = value;
            return x;
        }
        // Use d-th key char to identify the sub-trie node
        int c = (int) key[d];
        x->next[c] = put(x->next[c], key, value, d + 1);
        return x;
    }
    // Return node associated with key in teh sub-trie rooted at 'x'
    Node* get(Node *x, std::string key, int d) {
        if (x == nullptr)
            return nullptr;
        if (d == key.length()) {
            return x;
        }
        // Use d-th key char to identify the sub-trie node
        int c = (int) key[d];
        return get(x->next[c], key, d + 1);
    }
    /* Number of keys in the trie
     * Avoid recursive solution for performance
     */
    int size(Node *x) {
        if (x == nullptr)
            return 0;
        int count = 0;
        if (x->value != nullptr)
            count++;
        for(int c = 0; c < R; c++) {
            count += size(x->next[c]);
        }
    }
    // Collecting keys with prefix
    void collect(Node *x, std::string prefix, std::queue<std::string> q) {
        if (x == nullptr)
            return;
        if (x->value != nullptr) {
            q.push(prefix);
        }
        for (int c = 0; c < R; c++) {
            collect(x->next[c], prefix + (char) c, q);
        }
    }
    // collect keys that match
    void collect(Node *x, std::string prefix, std::string pattern, std::queue<std::string> q) {
        int d = prefix.length();
        if (x == nullptr)
            return;
        if (d == pattern.length()) {
            if (x->value != nullptr)
                q.push(prefix);
            return;
        }
        char next = pattern[d];
        for (int c = 0; c < R; c++) {
            if (next == '.' || next == c) {
                collect(x->next[c], prefix + (char) c, pattern, q);
            }
        }
    }
    // Matching the longest prefix of a given string
    int search(Node *x, std::string s, int d, int length) {
        if (x == nullptr)
            return length;
        if (x->value != nullptr)
            length = d;
        if (d == s.length())
            return length;
        int c = s[d];
        return search(x->next[c], s, d + 1, length);
    }
    // Deleting a key (and its associated value) from trie
    Node* delete_key(Node *x, std::string key, int d) {
        if (x == nullptr)
            return nullptr;
        if (d == key.length()) {
            if (x->value)
                delete x->value;
            x->value = nullptr;
        } else {
            int c = key[d];
            x->next[c] = delete_key(x->next[c], key, d + 1);
        }
        if (x->value != nullptr) {
            return x;
        }
        for (int c = 0; c < R; c++) {
            if (x->next[c] != nullptr)
                return x;
        }
        return nullptr;
    }
public:
    TrieST() {
        root = new Node();
    }
    ~TrieST() {
        delete_nodes(root);
    }
    void delete_nodes(Node *node) {
        if (node == nullptr)
            return;
        if (node->value)
            delete node->value;
        for(int c = 0; c < R; c++) {
            delete_nodes(node->next[c]);
        }
    }
    int size() {
        return size(root);
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
    // Collecting keys with prefix
    std::queue<std::string> keys_with_prefix(std::string prefix) {
        std::queue<std::string> q;
        collect(get(root, prefix, 0), prefix, q);
        return q;
    }
    std::queue<std::string> keys() {
        return keys_with_prefix(std::string());
    }
    // Wildcard match
    std::queue<std::string> keys_that_match(std::string pattern) {
        std::queue<std::string> q;
        collect(get(root, std::string(), 0), pattern, q);
        return q;
    }
    // Longest prefix
    std::string longest_prefix_of(std::string s) {
        int length = search(root, s, 0, 0);
        return s.substr(0, length);
    }
    // Deletion
    void delete_key(std::string key) {
        root = delete_key(root, key, 0);
    }
};






