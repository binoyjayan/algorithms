#include <string>
#include <queue>
#include <iostream>
#include "tst.h"
using namespace std;

int main() {
    TST<string> tst;

    tst.put("she", new string("pronoun"));
    tst.put("sells", new string("verb"));
    tst.put("sea", new string("noun"));
    tst.put("shells", new string("noun"));
    tst.put("on", new string("preposition"));
    tst.put("the", new string("article"));
    tst.put("shore", new string("noun"));

    // print_queue("keys", trie.keys());

    return 0;
}
