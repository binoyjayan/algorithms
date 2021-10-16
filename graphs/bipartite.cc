#include <vector>
#include <iostream>
#include "graph.h"
using namespace std;

class Bipartite {
    vector<bool> m_marked;
    vector<int> m_color;
    bool m_is_bipartite;
public:
    Bipartite(Graph g) {
        m_is_bipartite = true;
        m_marked.insert(m_marked.end(), g.V(), false);
        m_color.insert(m_color.end(), g.V(), 0);
        bipartite(g);
    }

    void bipartite(Graph g) {
        for (int v = 0; v < g.adj().size(); v++) {
            m_color[v] = false;
        }
        for (int v = 0; v < g.adj().size(); v++) {
            if (!m_marked[v])
                dfs(g, v);
        }
    }
    void dfs(Graph g, int v) {
        m_marked[v] =  true;

        for (auto w: g.adj(v)) {
            if (!m_marked[w]) {
                m_color[w] = !m_color[v];
                dfs(g, w);
            } else if (m_color[w] == m_color[v]) {
                m_is_bipartite = false;
            }
        }
    }
    bool is_bipartite() {
        return m_is_bipartite;
    }
};

int main() {
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 0);

    cout << "V: " << g.V() << endl;
    cout << "E: " << g.E() << endl;

    Bipartite d(g);
    const char *is_bipartite = d.is_bipartite() ? "true": "false";
    cout << "Is bipartite:" << is_bipartite << endl;
    return 0;
}

