#include <map>
#include <vector>
#include <iostream>
#include "graph.h"

using namespace std;

class Cycle {
    // can be an array if nodes values are 0..N-1
    map<int, int> m_marked;
    bool m_has_cycle;
public:
    Cycle(Graph g) {
        m_has_cycle = false;
        cycle(g);
    }

    void cycle(Graph g) {
        for (auto n: g.adj()) {
            auto v = n.first;
            if (!m_marked[v])
                dfs(g, v, -1);
        }
    }
    void dfs(Graph g, int v, int parent) {
        m_marked[v] =  true;

        for (auto w: g.adj(v)) {
            if (!m_marked[w])
                dfs(g, w, v);
            // If an adjacent vertex is visited and
            // is not parent of current vertex,
            // then there exists a cycle in the graph.
            else if (w != parent)
                m_has_cycle = true;
        }
    }
    bool has_cycle() {
        return m_has_cycle;
    }
};

int main() {
    Graph g;
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.add_edge(4, 1);

    cout << "V: " << g.V() << endl;
    cout << "E: " << g.E() << endl;

    Cycle d(g);
    const char *has_cycle = d.has_cycle() ? "true": "false";
    cout << "Has cycle:" << has_cycle << endl;
    return 0;
}

