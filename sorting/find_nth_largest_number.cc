/*
 * Find nth largest element in an array using quick selection
 * A different algorithm can be used for this purpose using min heap
 * It is described in the 'searching' algorithms.
 */
#include <vector>
#include <ctime>
#include <chrono>
#include <random>
#include <iostream>
#include <iomanip>
using namespace std;

void swap(vector<int>&a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void print_vector(const std::string s, const std::vector<int>& nums) {
    std::cout << s << " [";
    for (int i = 0; i < nums.size(); i++) {
        std::cout << std::setw(2) << nums[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

int partition(vector<int> &a, int left, int right) {
    int i = left;
    int j = right + 1;
    int v = a[left]; //partitioning element
    while (true) {
        while (a[++i] < v) if (i == right) break;
        while (v < a[--j]) if (j == left) break;
        if (i >= j) break;
        swap(a, i, j);
    }
  swap(a, left, j);
    return j;
}

void print(vector<int> &a) {
    cout << "[";
    for (auto n: a) {
        cout << n << ",";
    }
    cout << "]" << endl;
}

// Quick Select algorithm designed for selecting kth element
int selection(vector<int> &a, int k) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (a.begin(), a.end(), std::default_random_engine(seed));
    int left = 0;
    int right = a.size() - 1;
    while (left < right) {
        int j = partition(a, left, right);
        if (j < k)
            left = j + 1;
        else if (j > k)
            right = j - 1;
        else
            return a[k];
    }
    return a[k];
}

// this find 3rd largest number. this can also be made generic.
vector<int> findThreeLargestNumbers(vector<int> array) {
  // Write your code here.
    int n = array.size();
    int n1 = selection(array, n - 1);
    int n2 = selection(array, n - 2);
    int n3 = selection(array, n - 3);
  return {n3, n2, n1};
}

int main() {
    std::vector<int> array = {9, 6, 5, 10, 4, 7, 1, 3, 2, 8};
    print_vector("NUmbers", array);

    cout << "3rd largest: " << selection(array, array.size() - 3) << endl;
    return 0;
}
