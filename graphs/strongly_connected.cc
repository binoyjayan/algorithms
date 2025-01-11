#include <vector>
#include <iostream>
#include "digraph.h"
#include "depth_first_order.h"
using namespace std;

/*
 * Two vertices v and w are strongly connected if they are mutually
 * reachable: i.e. if there is a directed path from v to w and
 * a directed path from w to v.
 */
class KosarajuSharirSCC {
    vector<bool> m_marked;
    vector<int> m_id;
    int m_count = 0;
public:
    KosarajuSharirSCC(DiGraph g) {
        m_marked.insert(m_marked.end(), g.V(), false);
        m_id.insert(m_id.end(), g.V(), 0);
        strongly_connected_components(g);
    }

    void dfs(DiGraph g, int v) {
        m_marked[v] =  true;
        m_id[v] = m_count;
        for (auto w: g.adj(v)) {
            if (!m_marked[w])
                dfs(g, w);
        }
    }
    void strongly_connected_components(DiGraph g) {
        DepthFirstOrder dfo(g.reverse());
        auto order = dfo.reverse_postorder();
        // 'order' is a stack data structure, so iterate accordingly
        for (auto it = order.rbegin(); it != order.rend(); ++it) {
            auto v = *it;
            if (!m_marked[v]) {
                dfs(g, v);
                m_count++;
            }
        }
    }
    bool strongly_connected(int v,int w) {
        return m_id[v] == m_id[w];
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

void print_stack(string s, deque<int> stack) {
    cout << s << ": [ ";
    for (auto v = stack.rbegin(); v != stack.rend(); ++v) {
        cout << *v << ", ";
    }
    cout << " ]" << endl;
}

int main() {
    DiGraph g(6);
    // Strongly connected components (0, 1, 2)
    // 0 -> 1 -> 2 -> 0
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 0);

    g.add_edge(2, 3);

    // Strongly connected components (3, 4 ,5)
    // 3 -> 4 -> 5 -> 3
    g.add_edge(3, 4);
    g.add_edge(4, 5);
    g.add_edge(5, 3);


    cout << "V: " << g.V() << endl;
    cout << "E: " << g.E() << endl;

    DepthFirstOrder order(g.reverse());
    print_stack("reverse postorder", order.reverse_postorder());

    KosarajuSharirSCC d(g);
    cout << "Number of strongly connected components: "  << d.count() << endl;

    // Print IDs of all components
    for (int v = 0; v < g.adj().size(); v++) {
        cout << "id[" << v << "]: "  << d.id(v) << endl;
    }
    return 0;
}

