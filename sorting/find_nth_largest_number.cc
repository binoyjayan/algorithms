#include <iostream>
#include <vector>
#include "pq_max.h"

void print_vector(vector<int> a) {
    cout << "ARR: [";
    for (auto n: a) {
        cout << n << ",";
    }
    cout << "]" << endl;
}

int find_nth_largest(MaxPQ& pq, int n) {
    while(--n) {
        pq.del_max();
    }
    return pq.del_max();
}


int main() {
    std::vector<int> array = {8, 10, 9, 6, 5, 4, 7, 1, 3, 2};
    print_vector(array);
    MaxPQ pq_max(array.size());
    for(auto n: array) {        
        pq_max.insert(n);
    }
    cout << "3rd largest: " << find_nth_largest(pq_max, 3) << endl;
    return 0;
}

