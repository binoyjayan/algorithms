#include <map>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Graph {
    int m_E;
    map<int, vector<int> > m_adj; // adjacency list
public:
    int V() {
        return m_adj.size();
    }
    int E() { return m_E; }

    void add_edge(int v, int w) {
        m_adj[v].push_back(w);
        m_adj[w].push_back(v);
        m_E++;
    }
    vector<int> adj(int v) {
        return m_adj[v];
    }
};

class DFS {
    bool *m_marked;
    vector<int> m_items;
public:
    DFS(Graph g, int s) {
        m_marked = new bool[g.V()];
        dfs(g, s);
    }
    ~DFS() {
        delete m_marked;
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

    DFS d(g, 1);
    vector<int> v = d.items();
    print_vector(v);
    return 0;
}

