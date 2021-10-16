#include <vector>
#include <stack>
#include <iostream>
#include "digraph.h"

using namespace std;

class DirectedCycle {
    vector<bool> m_marked;
    vector<int> m_edge_to;
    vector<bool> m_on_stack;  // vertices on function call stack
    deque<int> m_cycle;       // vertices on a cycle, if it exists
public:
    DirectedCycle(DiGraph g) {
        m_marked.insert(m_marked.end(), g.V(), false);
        m_edge_to.insert(m_edge_to.end(), g.V(), 0);
        m_on_stack.insert(m_on_stack.end(), g.V(), false);
        directed_cycle(g);
    }
    void directed_cycle(DiGraph g) {
        for (int v = 0; v < g.V(); v++) {
            if (!m_marked[v]) {
                dfs(g, v);
            }
        }
    }

    void dfs(DiGraph g, int v) {
        m_marked[v] =  true;
        m_on_stack[v] = true;

        for (auto w: g.adj(v)) {
            if (has_cycle()) {
                return;
            } else if (!m_marked[w]) {
                m_edge_to[w] = v;
                dfs(g, w);
            } else if (m_on_stack[w]) {
                m_cycle.clear();
                for (int x = v; x != w; x = m_edge_to[x]) {
                    // cout << "push " << x << endl;
                    m_cycle.push_back(x);
                }
                m_cycle.push_back(w);
                m_cycle.push_back(v);
            }
        }
        m_on_stack[v] = false;
    }
    bool marked(int w) {
        return m_marked[w];
    }
    bool has_cycle() {
        return !m_cycle.empty();
    }
    deque<int> cycle() {
        return m_cycle;
    }
};

