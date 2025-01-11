#include <vector>
#include <iostream>
#include "digraph.h"

using namespace std;

class DirectedDFS {
    bool *m_marked;
    vector<int> m_items;
public:
    DirectedDFS(DiGraph g, int s) {
        m_marked = new bool[g.V()];
        dfs(g, s);
    }
    ~DirectedDFS() {
        delete m_marked;
    }

    void dfs(DiGraph g, int v) {
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

void do_dfs(DiGraph &g, int start) {
    cout << "DFS starting node " << start << endl;
    DirectedDFS d(g, start);
    vector<int> v = d.items();
    print_vector(v);
}

int main() {
    DiGraph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 3);
    g.add_edge(2, 3);

    cout << "V: " << g.V() << endl;
    cout << "E: " << g.E() << endl;

    do_dfs(g, 0);
    do_dfs(g, 1);
    do_dfs(g, 2);
    do_dfs(g, 3);
    return 0;
}

