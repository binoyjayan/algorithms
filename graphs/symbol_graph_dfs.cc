#include <vector>
#include <iostream>
#include "graph.h"
#include "symbol_graph.h"
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

void print_vector(SymbolGraph &sg, vector<int> &vect) {
   cout << "[ ";
   for (auto v: vect) {
       string v_str = sg.name_of(v);
      cout << v_str << ", ";
   }
   cout << " ]" << endl;
}

int main() {
    SymbolGraph sg(4);
    Graph *g = sg.G();
    sg.add_edge("A", "B");
    sg.add_edge("A", "C");
    sg.add_edge("A", "D");
    sg.add_edge("B", "D");
    sg.add_edge("C", "D");


    cout << "V: " << sg.V() << endl;
    cout << "E: " << sg.E() << endl;

    DFS d(*g, 0);
    vector<int> v = d.items();
    print_vector(sg, v);
    return 0;
}

