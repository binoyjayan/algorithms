#pragma once
#include <map>
#include <vector>
using namespace std;

class Graph {
    int m_E;
    std::map<int, std::vector<int> > m_adj; // adjacency list
public:
    int V() {
        return m_adj.size();
    }
    int E() { return m_E; }

    void add_edge(int v, int w) {
        m_adj[v].push_back(w);
        m_adj[w].push_back(v);
        m_E++;
    }
    std::vector<int> adj(int v) {
        return m_adj[v];
    }
    std::map<int, std::vector<int> > adj() {
        return m_adj;
    }
};


