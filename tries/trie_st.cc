#include <string>
#include <queue>
#include <iostream>
#include "trie_st.h"
using namespace std;

void print_queue(string msg, queue<string> keys) {
    cout << "[ ";
    while(!keys.empty()) {
        string k = keys.front();
        std::cout << k << ", ";
        keys.pop();
    }
    std::cout << endl;
}

int main() {
    TrieST<string> trie;

    trie.put("she", new string("pronoun"));
    trie.put("sells", new string("verb"));
    trie.put("sea", new string("noun"));
    trie.put("shells", new string("noun"));
    trie.put("on", new string("preposition"));
    trie.put("the", new string("article"));
    trie.put("shore", new string("noun"));

    print_queue("keys", trie.keys());

    return 0;
}
