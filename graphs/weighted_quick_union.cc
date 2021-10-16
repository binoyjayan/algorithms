#include <vector>
#include <fstream>
#include <iostream>
#include "weighted_quick_union.h"
using namespace std;

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
    WeightedQuickUnion uf(n);
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

