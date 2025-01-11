#include <vector>
#include <iostream>
#include "pq_min.h"
#include "pq_max.h"
using namespace std;

// Heap sort using priority queue

void print_vector(vector<int> a) {
    cout << "ARR: [";
    for (auto n: a) {
        cout << n << ",";
    }
    cout << "]" << endl;
}

void print_pq(MinPQ &pq) {
    cout << "ASC: [";
    while(!pq.empty()) {
        int max = pq.del_min();
        cout << max << ", ";
    }
    cout << "]" << endl;
}

void print_pq(MaxPQ &pq) {
    cout << "DESC: [";
    while(!pq.empty()) {
        int max = pq.del_max();
        cout << max << ", ";
    }
    cout << "]" << endl;
}

int main() {
    vector<int> array = {141, 1, 17, -7, -17, -27, 18, 541, 8, 7};
    print_vector(array);
    MinPQ pq_min(array.size());
    MaxPQ pq_max(array.size());

    for(auto n: array) {
        pq_min.insert(n);
        pq_max.insert(n);
    }
    print_pq(pq_min);
    print_pq(pq_max);
    return 0;
}


