#pragma once
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

class Edge {
    int m_v;
    int m_w;
    double m_weight;
public:
    Edge(int v, int w, double weight) {
        m_v = v;
        m_w = w;
        m_weight = weight;
    }
    double weight() {return m_weight; }
    int either() {return m_v; }
    int other(int vtx) {
        if (vtx == m_v) return m_w;
        else if (vtx == m_w) return m_v;
        else return -1;
    }
    string to_string() {
        char tmp[128];
        snprintf(tmp, sizeof(tmp), "%d-%d %.2f", m_v, m_w, m_weight);
        return string(tmp);
    }
};

class EdgeCompareLT {
public:
    bool operator() (Edge& lhs, Edge& rhs) {
        return (lhs.weight() < rhs.weight());
    }
};

class EdgeCompareGT {
public:
    bool operator() (Edge& lhs, Edge& rhs) {
        return (lhs.weight() > rhs.weight());
    }
};

class EdgeWeightedGraph {
    int m_E;
    // adjacency list
    std::vector<std::vector<Edge> > m_adj;
public:
    EdgeWeightedGraph(int sz) {
        m_E = 0;
        m_adj.insert(m_adj.end(), sz, {});
    }
    int V() {
        return m_adj.size();
    }
    int E() {
        return m_E;
    }
    void add_edge(Edge e) {
        int v = e.either();
        int w = e.other(v);
        m_adj[v].push_back(e);
        m_adj[w].push_back(e);
        m_E++;
    }
    void add_edge(int v, int w, double weight) {
        Edge e(v, w, weight);
        m_adj[v].push_back(e);
        m_adj[w].push_back(e);
        m_E++;
    }
    std::vector<Edge> adj(int v) {
        return m_adj[v];
    }
    std::vector<std::vector<Edge> > adj() {
        return m_adj;
    }
    std::vector<Edge> edges() {
        std::vector<Edge> edges;
        for (int v = 0; v < V(); v++) {
            for (auto e: m_adj[v]) {
                if (e.other(v) > v)
                    edges.push_back(e);
            }
        }
        return edges;
    }
};


