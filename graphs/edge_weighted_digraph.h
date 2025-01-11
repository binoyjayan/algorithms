#pragma once
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

class DirectedEdge {
    int m_v;
    int m_w;
    double m_weight;
public:
    // A way to mark null edges
    DirectedEdge() {
        m_v = m_w = -1;
        m_weight = 0.0;
    }
    DirectedEdge(int v, int w, double weight) {
        m_v = v;
        m_w = w;
        m_weight = weight;
    }
    double weight() { return m_weight; }
    int from() { return m_v; }
    int to() { return m_w; }
    string to_string() {
        char tmp[128];
        snprintf(tmp, sizeof(tmp), "%d-%d %.2f", m_v, m_w, m_weight);
        return string(tmp);
    }
    bool is_null() { return m_v == -1 && m_w == -1; }
};

class DirectedEdgeCompareLT {
public:
    bool operator() (DirectedEdge& lhs, DirectedEdge& rhs) {
        return (lhs.weight() < rhs.weight());
    }
};

class DirectedEdgeCompareGT {
public:
    bool operator() (DirectedEdge& lhs, DirectedEdge& rhs) {
        return (lhs.weight() > rhs.weight());
    }
};

class EdgeWeightedDiGraph {
    int m_E;
    // adjacency list
    std::vector<std::vector<DirectedEdge> > m_adj;
public:
    EdgeWeightedDiGraph(int sz) {
        m_E = 0;
        m_adj.insert(m_adj.end(), sz, {});
    }
    int V() {
        return m_adj.size();
    }
    int E() {
        return m_E;
    }
    void add_edge(DirectedEdge e) {
        int v = e.from(), w = e.to();
        m_adj[v].push_back(e);
        // m_adj[w].push_back(e);
        m_E++;
    }
    void add_edge(int v, int w, double weight) {
        DirectedEdge e(v, w, weight);
        m_adj[v].push_back(e);
        // m_adj[w].push_back(e);
        m_E++;
    }
    std::vector<DirectedEdge> adj(int v) {
        return m_adj[v];
    }
    std::vector<std::vector<DirectedEdge> > adj() {
        return m_adj;
    }
    std::vector<DirectedEdge> edges() {
        std::vector<DirectedEdge> edges;
        for (int v = 0; v < V(); v++) {
            for (auto e: m_adj[v]) {
                edges.push_back(e);
            }
        }
        return edges;
    }
};


