#include <vector>
#include <iostream>
#include "edge_weighted_graph.h"
using namespace std;

class EdgeWeightedGraphDFS {
    vector<bool> m_marked;
    vector<int> m_items;
public:
    EdgeWeightedGraphDFS(EdgeWeightedGraph g, int s) {
        m_marked.insert(m_marked.end(), g.V(), false);
        dfs(g, s);
    }

    void dfs(EdgeWeightedGraph g, int v) {
        m_marked[v] =  true;
        m_items.push_back(v);

        for (auto e: g.adj(v)) {
            auto w = e.other(v);
            if (!m_marked[w])
                dfs(g, w);
        }
    }
    bool marked(int w) {
        return m_marked[w];
    }
    vector<int> items() {
        return m_items;
    }
};

void print_vector(vector<int> &vect) {
   cout << "[ ";
   for (auto v: vect) {
      cout << v << ", ";
   }
   cout << " ]" << endl;
}

int main() {
    EdgeWeightedGraph g(8);
    g.add_edge(0, 1, 1.0);
    g.add_edge(0, 2, 1.0);
    g.add_edge(0, 4, 1.0);
    g.add_edge(1, 5, 1.0);
    g.add_edge(2, 6, 1.0);
    g.add_edge(3, 7, 1.0);
    g.add_edge(4, 3, 1.0);
    g.add_edge(4, 5, 1.0);
    g.add_edge(5, 7, 1.0);
    g.add_edge(6, 7, 1.0);

    cout << "V: " << g.V() << endl;
    cout << "E: " << g.E() << endl;

    EdgeWeightedGraphDFS d(g, 1);
    vector<int> v = d.items();
    print_vector(v);
    return 0;
}

