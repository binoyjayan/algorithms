#pragma once
#include <map>
#include <vector>
#include "graph.h"
using namespace std;

class SymbolGraph {
    Graph *m_G;
    map<string, int> m_st;     // symbol table
    vector<string> m_strings;  // string from integer
public:
    SymbolGraph(int sz) {
        m_G = new Graph(sz);
    }
    ~SymbolGraph() {
        delete m_G;
    }
    int V() { return m_G->V(); }
    int E() { return m_G->E(); }

    Graph* G() {
        return m_G;
    }
    void add_edge(string v_str, string w_str) {
        int v, w;
        if (m_st.find(v_str) == m_st.end()) {
            v = m_strings.size();
            m_strings.push_back(v_str);
            m_st[v_str] = v;
        } else {
            v = m_st[v_str];
        }
        if (m_st.find(w_str) == m_st.end()) {
            w = m_strings.size();
            m_strings.push_back(w_str);
            m_st[w_str] = w;
        } else {
            w = m_st[w_str];
        }
        m_G->add_edge(v, w);
    }
    string name_of(int v) {
        return m_strings[v];
    }
};


