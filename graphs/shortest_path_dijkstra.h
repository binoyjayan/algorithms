#pragma once
#include <vector>
#include <stack>
#include <limits>
#include <iostream>
#include "pq_index_min.h"
#include "edge_weighted_digraph.h"

/*
 * Edge relaxation:
 * To relax an edge v->w means to test whether the best known way
 * from s to w is to go from s to v, then take the edge from v to w,
 * and, if so, update data structure to indicate that.
 *
 * Vertex relaxation:
 * Any edge v->w from a vertex whose dist_to[v] entry is finite to
 * a vertex whose dist_to[w] is infinite is eligible and will be
 * added to edge_to[w] if relaxed.
 */

class DijkstraSP {
    DirectedEdge *m_edge_to;
    double *m_dist_to;
    IndexMinPQ<double> *m_pq;
public:
    DijkstraSP(EdgeWeightedDiGraph g, int s) {
        m_edge_to = new DirectedEdge[g.V()];
        m_dist_to = new double[g.V()];
        m_pq = new IndexMinPQ<double>(g.V());

        for (int v = 0; v < g.V(); v++) {
            m_dist_to[v] = numeric_limits<double>::max();
        }
        m_dist_to[s] = 0.0;         // distance to source is zero
        m_pq->insert(s, 0.0);  // insert the same into the pq also
        while (!m_pq->empty()) {
            int min = m_pq->del_min();
            relax(g, min);
        }
    }
    ~DijkstraSP() {
        delete m_edge_to;
        delete m_dist_to;
        delete m_pq;
    }
    void relax(EdgeWeightedDiGraph g, int v) {
        for (auto e: g.adj(v)) {
            int w = e.to();
            if (m_dist_to[w] > m_dist_to[v] + e.weight()) {
                m_dist_to[w] = m_dist_to[v] + e.weight();
                m_edge_to[w] = e;
                if (m_pq->contains(w)) {
                    m_pq->change_key(w, m_dist_to[w]);
                } else {
                    m_pq->insert(w, m_dist_to[w]);
                }
            }
        }
    }
    // Client query methods for shortest paths
    double dist_to(int v) { return m_dist_to[v]; }
    bool has_path_to(int v) { return m_dist_to[v] < numeric_limits<double>::max(); }

    std::stack<DirectedEdge> path_to(int v) {
        std::stack<DirectedEdge> path;
        if (!has_path_to(v))
            return path;
        for (DirectedEdge e = m_edge_to[v]; !e.is_null(); e = m_edge_to[e.from()]) {
            path.push(e);
        }
        return path;
    }
};

