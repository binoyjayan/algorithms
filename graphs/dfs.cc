#include <vector>
#include <iostream>
#include "graph.h"
using namespace std;

class DFS {
    vector<bool> m_marked;
    vector<int> m_items;
public:
    DFS(Graph g, int s) {
        m_marked.insert(m_marked.end(), g.V(), false);
        dfs(g, s);
    }

    void dfs(Graph g, int v) {
        m_marked[v] =  true;
        m_items.push_back(v);

        for (auto w: g.adj(v)) {
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

    DFS d(g, 1);
    vector<int> v = d.items();
    print_vector(v);
    return 0;
}

