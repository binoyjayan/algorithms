#include <queue>
#include <vector>
#include <iostream>
#include <unordered_set>
#include "graph.h"

using namespace std;

class BFS {
    vector<bool> m_marked;
    vector<int> m_edge_to;
    vector<int> m_items;
public:
    BFS(Graph g, int s) {
        m_marked.insert(m_marked.end(), g.V(), false);
        m_edge_to.insert(m_edge_to.end(), g.V(), 0);
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

    BFS d(g, 0);
    vector<int> v = d.items();
    print_vector(v);
    return 0;
}

