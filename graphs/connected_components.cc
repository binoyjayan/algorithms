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
    map<int, vector<int> > adj() {
        return m_adj;
    }
};

class CC {
    // can be an array if nodes values are 0..N-1
    map<int, int> m_marked;
    map<int, int> m_id;
    int m_count = 0;
public:
    CC(Graph g) {
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
        for (auto n: g.adj()) {
            auto v = n.first;
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

    CC d(g);
    cout << "Number of connected components: "  << d.count() << endl;

    // Print IDs of all connected components
    for (auto n: g.adj()) {
        int v = n.first;
        cout << "id[" << v << "]: "  << d.id(v) << endl;
    }
    return 0;
}

