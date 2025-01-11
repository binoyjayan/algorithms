#include <vector>
#include <iostream>
#include "graph.h"
using namespace std;

class CC {
    vector<bool> m_marked;
    vector<int> m_id;
    int m_count = 0;
public:
    CC(Graph g) {
        m_marked.insert(m_marked.end(), g.V(), false);
        m_id.insert(m_id.end(), g.V(), 0);
        connected_components(g);
    }

    void dfs(Graph g, int v) {
        m_marked[v] =  true;
        m_id[v] = m_count;
        for (auto w: g.adj(v)) {
            if (!m_marked[w])
                dfs(g, w);
        }
    }
    void connected_components(Graph g) {
        for (int v = 0; v < g.V(); v++) {
            if (!m_marked[v]) {
                dfs(g, v);
                m_count++;
            }
        }
    }
    int count() { return m_count; }
    int id(int v) { return m_id[v]; }
};

void print_vector(vector<int> &vect) {
   cout << "[ ";
   for (auto v: vect) {
      cout << v << ", ";
   }
   cout << " ]" << endl;
}

int main() {
    Graph g(8);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 4);
    g.add_edge(1, 5);
    g.add_edge(2, 6);
    g.add_edge(3, 7);
    g.add_edge(4, 3);
    g.add_edge(4, 5);
    g.add_edge(5, 7);
    g.add_edge(6, 7);

    cout << "V: " << g.V() << endl;
    cout << "E: " << g.E() << endl;

    CC d(g);
    cout << "Number of connected components: "  << d.count() << endl;

    // Print IDs of all connected components
    for (int v = 0; v < g.adj().size(); v++) {
        cout << "id[" << v << "]: "  << d.id(v) << endl;
    }
    return 0;
}

