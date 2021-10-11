#include <map>
#include <vector>
#include <iostream>
#include "graph.h"
using namespace std;

class Bipartite {
    // can be an array if nodes values are 0..N-1
    map<int, int> m_marked;
    map<int, int> m_color;
    bool m_is_bipartite;
public:
    Bipartite(Graph g) {
        m_is_bipartite = true;
        bipartite(g);
    }

    void bipartite(Graph g) {
        for (auto n: g.adj()) {
            auto v = n.first;
            m_color[v] = false;
        }
        for (auto n: g.adj()) {
            auto v = n.first;
            if (!m_marked[v])
                dfs(g, v);
        }
    }
    void dfs(Graph g, int v) {
        m_marked[v] =  true;

        for (auto w: g.adj(v)) {
            if (!m_marked[w])
                dfs(g, w);
            else if (m_color[w] == m_color[v])
                m_is_bipartite = false;
        }
    }
    bool is_bipartite() {
        return m_is_bipartite;
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

    Bipartite d(g);
    const char *is_bipartite = d.is_bipartite() ? "true": "false";
    cout << "Is bipartite:" << is_bipartite << endl;
    return 0;
}

