#include <vector>
using namespace std;

/*
 * Min oriented Priority Queue
 */
class MinPQ {
    // heap ordered complete binary tree
    vector<int> m_pq;
    int n = 0;
public:
    MinPQ(int maxN) {
        m_pq.push_back(0);
    }
    bool empty() { return n == 0; }
    int size() { return n; }
    bool more(int i, int j) {
        return m_pq[i] > m_pq[j];
    }
    void exch(int i, int j) {
        swap(m_pq[i], m_pq[j]);
    }
    void swim(int k) {
        while(k > 1 && more(k / 2 , k)) {
            exch(k / 2, k);
            k = k / 2;
        }
    }
    void sink(int k) {
        while(2 * k <= n) {
            int j = 2 * k;
            if (j < n && more(j, j + 1))
                j++;
            if (!more(k, j)) break;
            exch(k, j);
            k = j;
        }
    }

    void insert(int v) {
        m_pq.push_back(v);
        n++;
        swim(n);
    }
    int del_min() {
        int max = m_pq[1]; // Min key at the top
        exch(1, n--);
        m_pq.pop_back();
        sink(1);
        return max;
    }
};
