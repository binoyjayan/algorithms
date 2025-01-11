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
        m_pq.push_back(0);
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
            // Find the largest child's index
            if (j < n && less(j, j + 1))
                j++;
            // stop when parent is larger or equal to the largest child
            if (!less(k, j)) break;
            // swap parent with the largest child
            exch(k, j);
            k = j;
        }
    }

    void insert(int v) {
        m_pq.push_back(v);
        n++;
        swim(n);
    }
    int del_max() {
        // take the element at the top (1-indexed)
        int max = m_pq[1];
        // swap the top element with the last element
        exch(1, n--);
        // remove the last element
        m_pq.pop_back();
        sink(1);
        return max;
    }
};
