#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <functional>
#include "pq_max.h"
#include "pq_min.h"

void print_vector(const std::string s, const std::vector<int>& nums) {
    std::cout << s << " [";
    for (int i = 0; i < nums.size(); i++) {
        std::cout << std::setw(3) << nums[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

// Find nth largest element using max heap
int find_nth_largest_max(std::vector<int>& arr, int n) {
    MaxPQ pq(arr.size());
    for(auto n: arr) {
        pq.insert(n);
    }
    while(--n) {
        pq.del_max();
    }
    return pq.del_max();
}

// Find nth largest element using min heap
// Maintain only n largest elements:
// If the size of the heap exceeds n,
// remove the minimum element (smallest among the largest seen so far).
int find_nth_largest_min(std::vector<int>& arr, int n) {
    MinPQ pq(n);

    for (int num : arr) {
        pq.insert(num);
        // Ensue only 'n' elements
        if (pq.size() > n) {
            pq.del_min();
        }
    }
    // smallest among the n large  numbers
    return pq.del_min();
}

// Use STL
int find_nth_largest_stl(std::vector<int>& arr, int n) {
    // Min heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int num : arr) {
        pq.push(num);
         // Ensure the heap has at most n elements
        if (pq.size() > n) {
            pq.pop(); // Remove the smallest
        }
    }

    // smallest among the n large  numbers
    return pq.top();
}


int main() {
    std::vector<int> array = {9, 6, 5, 10, 4, 7, 1, 3, 2, 8};
    print_vector("Numbers", array);

    cout << "3rd largest: " << find_nth_largest_max(array, 3) << endl;
    cout << "3rd largest: " << find_nth_largest_min(array, 3) << endl;
    cout << "3rd largest: " << find_nth_largest_stl(array, 3) << endl;
    return 0;
}

