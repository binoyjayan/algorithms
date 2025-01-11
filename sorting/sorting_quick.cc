#include <vector>
#include <ctime>
#include <chrono>
#include <random>
#include <iostream>

using namespace std;

int partition(vector<int> &a, int lo, int hi) {
    int i = lo;
    int j = hi + 1;
    int v = a[lo]; //partitioning element
    while (true) {
        while (a[++i] < v) if (i == hi) break;
        while (v < a[--j]) if (j == lo) break;
        if (i >= j) break;
        swap(a[i], a[j]);
    }
    swap(a[lo], a[j]);
    return j;
}

void print(vector<int> a) {
    cout << "[";
    for (auto n: a) {
        cout << n << ",";
    }
    cout << "]" << endl;
}

void sort_quick(vector<int> &a, int lo, int hi) {
    if (hi <= lo)
        return;
    int j = partition(a, lo, hi);
    sort_quick(a, lo, j - 1);
    sort_quick(a, j + 1, hi);
}

void sort_quick(vector<int> &a) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (a.begin(), a.end(), std::default_random_engine(seed));
    sort_quick(a, 0, a.size() - 1);
}

int main ()
{
    vector<int> array = {141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7};
    print(array);
    sort_quick(array);
    print(array);
    return 0;
}


