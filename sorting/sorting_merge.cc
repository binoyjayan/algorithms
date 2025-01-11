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

void merge(vector<int> &a, vector<int> &aux, int lo, int mid, int hi) {
    for(int k = lo; k <= hi; k++) {
        aux[k] = a[k];
    }
    cout << "merge: lo:" << lo << ",mid:" << mid << ",hi:" << hi << endl;
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++) {
        if (i > mid) {
           a[k] = aux[j++];       // Exhausted items on left subarray
        } else if (j > hi) {
           a[k] = aux[i++];       // Exhausted items on right subarray
        } else {
            if (aux[i] < aux[j])
                a[k] = aux[i++];
            else
                a[k] = aux[j++];
        }
    }
}

void sort_merge(vector<int> &a, vector<int> &aux, int lo, int hi) {
    if (hi <= lo)
        return;
    cout << "sort_merge: lo:" << lo << ",hi:" << hi << endl;
    int mid = lo + (hi - lo) / 2;
    sort_merge(a, aux, lo, mid);
    sort_merge(a, aux, mid + 1, hi);
    merge(a, aux, lo, mid, hi);
}

void sort_merge(vector<int> &a) {
    vector<int> aux(a.size(), 0);
    sort_merge(a, aux, 0, a.size() - 1);
}

int main ()
{
    vector<int> array = {141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7};
    print(array);
    sort_merge(array);
    print(array);
    return 0;
}


