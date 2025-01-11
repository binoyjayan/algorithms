#include <vector>
#include <deque>
#include <iostream>
#include "digraph.h"
#include "depth_first_order.h"
#include "directed_cycle.h"

using namespace std;

// Reverse postorder in a DAG (Directed Acyclic Graph) is a topological sort.

class TopologicalOrder {
    bool m_has_order;
    deque<int> m_order;
public:
    TopologicalOrder(DiGraph g) {
        DirectedCycle cycle_finder(g);
        // A topological order exists only if the graph is a DAG
        if (!cycle_finder.has_cycle()) {
            m_has_order = true;
            DepthFirstOrder dfs(g);
            m_order = dfs.reverse_postorder();
        } else {
            m_has_order = false;
        };
    }
    deque<int> order() {
        return m_order;
    }
    bool has_order() {
        return m_has_order;
    }
};

void print_stack(string s, deque<int> stack) {
    cout << s << ": [ ";
    for (auto v = stack.rbegin(); v != stack.rend(); ++v) {
        cout << *v << ", ";
    }
    cout << " ]" << endl;
}

void print_order(TopologicalOrder &topo) {
    if (topo.has_order()) {
        print_stack("Topological postorder", topo.order());
    } else {
        cout << "No topological order exists\n";
    }
}

// Does not have cycles and thus is a DAG
void directed_graph_with_topological_order() {
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

    TopologicalOrder topo(g);
    print_order(topo);
}

// Has cycles and thus is not a DAG
void directed_graph_without_topological_order() {
    DiGraph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(4, 1);
    g.add_edge(2, 4);
    g.add_edge(3, 4);

    cout << "V: " << g.V() << endl;
    cout << "E: " << g.E() << endl;

    TopologicalOrder topo(g);
    print_order(topo);
}

int main() {
    directed_graph_with_topological_order();
    cout << endl;
    directed_graph_without_topological_order();
    return 0;
}
