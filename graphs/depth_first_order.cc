#include <vector>
#include <deque>
#include <iostream>
#include "digraph.h"
#include "depth_first_order.h"

using namespace std;

void print_queue(string s, deque<int> stack) {
    cout << s << ": [ ";
    for (auto v : stack) {
        cout << v << ", ";
    }
    cout << " ]" << endl;
}

void print_stack(string s, deque<int> stack) {
    cout << s << ": [ ";
    for (auto v = stack.rbegin(); v != stack.rend(); ++v) {
        cout << *v << ", ";
    }
    cout << " ]" << endl;
}

int main() {
    DiGraph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(1, 4);
    g.add_edge(2, 4);
    g.add_edge(3, 4);

    cout << "V: " << g.V() << endl;
    cout << "E: " << g.E() << endl;

    DepthFirstOrder d(g);
    print_queue("preorder", d.preorder());
    print_queue("postorder", d.postorder());
    print_stack("reverse postorder", d.reverse_postorder());

    return 0;
}

