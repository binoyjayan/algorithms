#include <vector>
using namespace std;

/*
 * Max oriented Priority Queue
 */
class MaxPQ {
    // heap ordered complete binary tree
    vector<int> m_pq;
    int n = 0;
public:
    MaxPQ(int maxN) {
        m_pq.insert(m_pq.end(), maxN + 1, 0);
    }
    bool empty() { return n == 0; }
    int size() { return n; }
    bool less(int i, int j) {
        return m_pq[i] < m_pq[j];
    }
    void exch(int i, int j) {
        swap(m_pq[i], m_pq[j]);
    }
    void swim(int k) {
        while(k > 1 && less(k / 2 , k)) {
            exch(k / 2, k);
            k = k / 2;
        }
    }
    void sink(int k) {
        while(2 * k <= n) {
            int j = 2 * k;
            if (j < n && less(j, j + 1))
                j++;
            if (!less(k, j)) break;
            exch(k, j);
            k = j;
        }
    }

    void insert(int v) {
        m_pq[++n] = v;
        swim(n);
    }
    int del_max() {
        int max = m_pq[1]; // Max key at the top
        exch(1, n--);
        m_pq[n + 1] = 0;  // avoid loitering?
        sink(1);
        return max;
    }
};
