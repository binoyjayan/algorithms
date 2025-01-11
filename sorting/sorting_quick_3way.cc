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

void sort_quick(vector<int> &a, int lo, int hi) {
    if (hi <= lo)
        return;
    int lt = lo, gt = hi;
    int v = a[lo];
    int i = lo + 1;
    while (i <= gt) {
        if (a[i] < v)
            swap(a[lt++], a[i++]);
        else if (a[i] > v)
            swap(a[i], a[gt--]);
        else
            i++;
    }
    // Now, a[lo..lt-1] < v = a[lt..gt] < a[gt+1..hi]
    sort_quick(a, lo, lt - 1);
    sort_quick(a, gt + 1, hi);
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


