#include <vector>
#include <deque>
#include <iostream>
#include "digraph.h"

using namespace std;

class DepthFirstOrder {
    vector<bool> m_marked;
    deque<int> m_pre;       // preorder (queue)
    deque<int> m_post;      // postorder (queue)
    deque<int> m_rev_post;  // reverse preorder (stack)
public:
    DepthFirstOrder(DiGraph g) {
        m_marked.insert(m_marked.end(), g.V(), false);
        depth_first_order(g);
    }
    void depth_first_order(DiGraph g) {
        for (int v = 0; v < g.V(); v++) {
            if (!m_marked[v]) {
                dfs(g, v);
            }
        }
    }
    void dfs(DiGraph g, int v) {
        m_pre.push_back(v);      // enqueue

        m_marked[v] =  true;
        for (auto w: g.adj(v)) {
            if (!m_marked[w])
                dfs(g, w);
        }
        m_post.push_back(v);     // enqueue
        m_rev_post.push_back(v); // push to stack
    }
    bool marked(int w) {
        return m_marked[w];
    }
    deque<int> preorder() {
        return m_pre;
    }
    deque<int> postorder() {
        return m_post;
    }
    deque<int> reverse_postorder() {
        return m_rev_post;
    }
};

