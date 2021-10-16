#include <vector>
#include <stack>
#include <iostream>
#include "digraph.h"
#include "directed_cycle.h"

using namespace std;

void print_cycle(deque<int> stack) {
   cout << "cycle: [ ";
    // for (auto v : stack)
    for (auto v = stack.rbegin(); v != stack.rend(); ++v) {
        cout << *v << ", ";
    }
   cout << " ]" << endl;
}

void directed_graph_with_cycle() {
    DiGraph g(4);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 0);

    cout << "V: " << g.V() << endl;
    cout << "E: " << g.E() << endl;

    DirectedCycle d(g);
    if (d.has_cycle())
        print_cycle(d.cycle());
    else
        cout << "No directed cycle\n";
}

void directed_graph_without_cycle() {
    DiGraph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 3);
    g.add_edge(2, 3);

    cout << "V: " << g.V() << endl;
    cout << "E: " << g.E() << endl;

    DirectedCycle d(g);
    if (d.has_cycle())
        print_cycle(d.cycle());
    else
        cout << "No directed cycle\n";
}

int main() {
    directed_graph_with_cycle();
    cout << endl;
    directed_graph_without_cycle();
    return 0;
}

