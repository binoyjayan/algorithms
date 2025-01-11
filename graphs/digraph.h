#pragma once
#include <vector>
using namespace std;

class DiGraph {
    int m_E;
    std::vector<std::vector<int> > m_adj; // adjacency list
public:
    DiGraph(int sz) {
        m_E = 0;
        m_adj.insert(m_adj.end(), sz, {});
    }
    int V() {
        return m_adj.size();
    }
    int E() { return m_E; }

    void add_edge(int v, int w) {
        m_adj[v].push_back(w); // only one edge v -> w
        m_E++;
    }
    std::vector<int> adj(int v) {
        return m_adj[v];
    }
    std::vector<std::vector<int> > adj() {
        return m_adj;
    }
    DiGraph reverse() {
        DiGraph R(m_adj.size());
        for (int v = 0; v < m_adj.size(); v++) {
            for (auto w: adj(v)) 
                R.add_edge(w, v);
        }
        return R;
    }
};


