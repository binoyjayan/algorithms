#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>
#include "graph.h"

using namespace std;

class BFS {
    // can be an array if nodes values are 0..N-1
    map<int, int> m_marked;
    map<int, int> m_edge_to;
    vector<int> m_items;
public:
    BFS(Graph g, int s) {
        bfs(g, s);
    }

    void bfs(Graph g, int v) {
        m_marked[v] =  true;
        queue<int> q = queue<int>();
        m_items.push_back(v);
        q.push(v);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int w: g.adj(v)) {
                if (!m_marked[w]) {
                    q.push(w);
                    m_marked[w] = true;
                    m_edge_to[w] = v;
                    m_items.push_back(w);
                }
            }
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
    Graph g;
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 5);
    g.add_edge(2, 6);
    g.add_edge(3, 7);
    g.add_edge(4, 8);
    g.add_edge(5, 4);
    g.add_edge(5, 6);
    g.add_edge(6, 8);
    g.add_edge(7, 8);

    cout << "V: " << g.V() << endl;
    cout << "E: " << g.E() << endl;

    BFS d(g, 1);
    vector<int> v = d.items();
    print_vector(v);
    return 0;
}

