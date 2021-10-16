#include <queue>
#include <vector>
#include <iostream>
#include <functional>
#include "edge_weighted_graph.h"
#include "weighted_quick_union.h"

using namespace std;

class KruskalMST {
    queue<Edge> m_mst;
    vector<bool> m_marked; // MST vertices
public:
    KruskalMST(EdgeWeightedGraph g) {
        m_marked.insert(m_marked.end(), g.V(), false);
        kruskal_mst(g);
    }

    void kruskal_mst(EdgeWeightedGraph& g) {
        priority_queue<Edge, vector<Edge>, EdgeCompareGT> pq;

        for (auto e: g.edges()) {
            pq.push(e);
        }
        WeightedQuickUnion uf(g.V());

        while(!pq.empty() && m_mst.size() < g.V() - 1) {
            // Get minimum edge on pq
            Edge e = pq.top();
            pq.pop();
            int v = e.either();
            int w = e.other(v);
            // Ignore edge that are not eligible
            if(uf.connected(v, w))
                continue;
            // Merge components (making them connected)
            uf.do_union(v, w);
            m_mst.push(e);
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

    KruskalMST mst(g);
    print_queue(mst.edges());
    return 0;
}

