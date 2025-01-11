#include <queue>
#include <vector>
#include <iostream>
#include <functional>
#include "edge_weighted_graph.h"
using namespace std;

class LazyPrimMST {
    vector<bool> m_marked; // MST vertices
    queue<Edge> m_mst;     // MST edges
    // Crossing edges and edges not eligible
    // Use EdgeCompareGT for Min-Priority-Queue
    priority_queue<Edge, vector<Edge>, EdgeCompareGT> m_pq;
public:
    LazyPrimMST(EdgeWeightedGraph g) {
        m_marked.insert(m_marked.end(), g.V(), false);
        lazy_prim_mst(g);
    }

    // O(E log(E))
    void lazy_prim_mst(EdgeWeightedGraph& g) {
        // Assume g is connected
        visit(g, 0);
        while (!m_pq.empty()) {
            // get lowest weighted edge from pq (deleteMinimum)
            auto e = m_pq.top();
            m_pq.pop();
            int v = e.either();
            int w = e.other(v);
            // skip if not eligible
            if (m_marked[v] && m_marked[w])
                continue;
            // add edge to spanning tree
            m_mst.push(e);
            if (!m_marked[v]) visit(g, v);
            if (!m_marked[w]) visit(g, w);
        }
    }
    // Mark v and add to pq all edges from v to unmarked vertices
    void visit(EdgeWeightedGraph& g, int v) {
        m_marked[v] =  true;
        for (auto e: g.adj(v)) {
            auto w = e.other(v);
            if (!m_marked[w])
                m_pq.push(e);
        }
    }
    bool marked(int w) {
        return m_marked[w];
    }
    queue<Edge> edges() {
        return m_mst;
    }
};

void print_queue(queue<Edge> edges) {
    cout << "[ ";
    while(!edges.empty()) {
        Edge e = edges.front();
        std::cout << e.to_string() << ", ";
        edges.pop();
    }
    std::cout << endl;
}


int main() {
    EdgeWeightedGraph g(5);
    g.add_edge(0, 1, 1.0);
    g.add_edge(0, 2, 1.0);
    g.add_edge(0, 3, 1.0);
    g.add_edge(1, 3, 1.0);
    g.add_edge(2, 3, 2.0);
    g.add_edge(2, 4, 1.0);
    g.add_edge(3, 4, 2.0);

    cout << "V: " << g.V() << endl;
    cout << "E: " << g.E() << endl;

    LazyPrimMST mst(g);
    print_queue(mst.edges());
    return 0;
}

