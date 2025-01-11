/*
 * Shell sort: Generalization of insertion sort
 * 
 * Rearrange array to give it a property that taking every h-th entry
 * (starting anywhere) yields a (interleaved) sorted subsequence.
 *
 */
#include <vector>
#include <ctime>
#include <chrono>
#include <random>
#include <iostream>

using namespace std;

void print(vector<int> a) {
    cout << "[";
    for (auto n: a) {
        cout << n << ",";
    }
    cout << "]" << endl;
}

void sort_shell(vector<int> &a) {
    int n = a.size();
    int h = 1;
    // Calculate the final 'h' in the sequence:
    // 1, 4, 13, 40, 121, 361, ...
    // Insertion sort is shell sort generalized for h = 1
    while (h < n / 3) h = 3 * h + 1;
    while (h >= 1) {
        for (int i = h; i < n; i++) {
            // insert a[i] among a[i-h], a[i-2h], ...
            for (int j = i; j >= h; j-=h) {
                if (a[j] < a[j-h])
                    swap(a[j], a[j-1]);
                else
                    break;
            }
        }
        h /= 3;
    }
}

int main ()
{
    vector<int> array = {141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7};
    print(array);
    sort_shell(array);
    print(array);
    return 0;
}


