#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class UF {
    int *m_id;
    int m_count;
public:
    UF(int n) {
      m_count = n;
      m_id = new int[n];
      for (int i = 0; i < n; i++)
          m_id[i] = i;
    }
    ~UF() {
        delete m_id;
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

        // Make component id of 'i' as 'j'
        m_id[i] = j;
        m_count--;
    }
};


int main(int argc, char *argv[]) {
    int n, p, q;
    if (argc < 2) {
        cout << "Usage:" << argv[0] << " <file-containing-numbers>\n";
        return 1;
    }
    ifstream fs(argv[1]);
    if (!fs.is_open()) {
        cout << "Failed to read " << argv[1] << endl;
        return 1;
    }
    fs >> n;
    cout << "Graph with " << n << " components\n";
    UF uf(n);
    while (!fs.eof()) {
        fs >> p >> q;
        if (uf.connected(p, q))
            continue;
        uf.do_union(p, q);
        cout << p << " " << q << endl;
    }
    fs.close();
    cout << "Connected components: " << uf.count() << endl;
    return 0;
}

