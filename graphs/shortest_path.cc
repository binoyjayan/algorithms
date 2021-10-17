#include <stdlib.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "edge_weighted_digraph.h"
#include "shortest_path_dijkstra.h"

void print_stack(stack<DirectedEdge> s) {
    while(!s.empty()) {
        auto e = s.top();
        std::cout << e.to_string() << ", ";
        s.pop();
    }
}

int main(int argc, char *argv[]) {
    int V, E, v, w, s;
    double weight;
    if (argc < 3) {
        cout << "Usage:" << argv[0] << " <edge-weighted-digraph-file - EWD> <start>\n";
        return 1;
    }
    s = strtol(argv[2], NULL, 10);
    // Read the edge-weighted Di-Graph
    ifstream fs(argv[1]);
    if (!fs.is_open()) {
        cout << "Failed to read " << argv[1] << endl;
        return 1;
    }
    fs >> V >> E;
    cout << "Edge Weighted Graph [V:" << V << ", E:" << E << "]\n";
    EdgeWeightedDiGraph g(V);
    int i = 0;
    while (!fs.eof() && i < E) {
        fs >> v >> w >> weight;
        cout << "(" << v << ", " << w << ", " << weight << ")" << endl;
        g.add_edge(v, w, weight);
        i++;
    }
    fs.close();

    // Process the DiGraph using Dijkstra's shortest path algorithm
    DijkstraSP sp(g, s);

    cout << "\nShortest Paths:\n";
    for (int t = 0; t < g.V(); t++) {
        cout << "[" << s << " -> " << t << "] ";
        std::cout << "(" << std::fixed << std::setw( 2 ) << std::setprecision(2)
                  << std::setfill( '0' ) << sp.dist_to(t) << "): ";
        if (sp.has_path_to(t)) {
            print_stack(sp.path_to(t));
        } else {
            printf("No path");
        }
        cout << endl;
    }
    return 0;
}

