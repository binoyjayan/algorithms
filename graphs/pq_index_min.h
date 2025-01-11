#include <vector>
using namespace std;

/*
 * Indexed Min oriented Priority Queue
 */
template <typename T>
class IndexMinPQ {
    int n;       // Number of elements on PQ
    int *m_pq;   // binary heap using 1-based indexing
    int *m_qp;   // inverse: qp[pq[i]] = pq[qp[i]] = i
    T *m_keys;   // items with priorities
public:
    IndexMinPQ(int maxN) {
        n  = 0;
        m_pq = new int[maxN + 1];
        m_qp = new int[maxN + 1];
        m_keys = new T[maxN + 1];
        for (int i = 0; i <= maxN; i++) {
            m_qp[i] = -1;
        }
    }
    ~IndexMinPQ() {
        delete m_pq;
        delete m_qp;
        delete m_keys;
    }
    bool empty() {
        return n == 0;
    }
    int size() {
        return n;
    }
    bool more(int i, int j) {
        return m_pq[i] > m_pq[j];
    }
    bool contains(int i) {
        return m_qp[i] != -1;
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

    void insert(int i, T key) {
        n++;
        m_qp[i] = n;
        m_pq[n] = i;
        m_keys[i] = key;
        swim(n);
    }
    T min_key() {
        return m_keys[m_pq[1]];
    }
    int min_index() {
        return m_pq[1];
    }
    int del_min() {
        int min_index = m_pq[1]; // Min key at the top
        exch(1, n--);
        sink(1);
        // m_keys[m_pq[n + 1]] = nullptr;   // avoid loitering
        m_qp[m_pq[n + 1]] = -1;
        return min_index;
    }
    void change_key(int i, T key) {
        m_keys[i] = key;
        swim(m_qp[i]);
        sink(m_qp[i]);
    }
    void delete_key(int i) {
        int idx = m_qp[i];
        exch(idx, n--);
        swim(idx);
        sink(idx);
        // m_keys[i] = null; // not possible with templates
        m_qp[i] = -1;
    }
};
