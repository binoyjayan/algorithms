#include <vector>
#include <fstream>
using namespace std;

class WeightedQuickUnion {
    int *m_id;     // parent link
    int *m_sz;     // size of component for roots
    int m_count;   // number of components
public:
    WeightedQuickUnion(int n) {
      m_count = n;
      m_id = new int[n];
      m_sz = new int[n];
      for (int i = 0; i < n; i++) {
          m_id[i] = i;
          m_sz[i] = 1; // start with size 1
      }
    }
    ~WeightedQuickUnion() {
        delete m_id;
        delete m_sz;
    }
    int count() {
        return m_count;
    }
    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    /*
     * Find operation is slower but not too slow
     * Follow links to the root. stop when the id is same as the element.
     */
    int find(int p) {
        // Find component id (same as the id of the root)
        while (p != m_id[p])
            p = m_id[p];
        return p;
    }
    // Union operation is quick
    void do_union(int p, int q) {
        // Give p and q the same root
        int i = find(p);
        int j = find(q);
        // Nothing to be done if p and q are already in the same component
        if (i == j) return;

        // Make smaller root point to larger one
        if (m_sz[i] < m_sz[j]) {
            m_id[i] = j;
            m_sz[j] += m_sz[i];
        } else {
            m_id[j] = i;
            m_sz[i] += m_sz[j];
        }
        m_count--;
    }
};
