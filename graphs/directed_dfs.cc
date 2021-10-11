#include <map>
#include <vector>
#include <iostream>
#include "digraph.h"

using namespace std;

class DirectedDFS {
    // can be an array if nodes values are 0..N-1
    map<int, int> m_marked;
    vector<int> m_items;
public:
    DirectedDFS(DiGraph g, int s) {
        dfs(g, s);
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

int main() {
    DiGraph g;
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 4);
    g.add_edge(3, 4);

    cout << "V: " << g.V() << endl;
    cout << "E: " << g.E() << endl;

    DirectedDFS d(g, 1);
    vector<int> v = d.items();
    print_vector(v);
    return 0;
}

