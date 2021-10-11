// Knuth shuffle

#include <vector>
#include <ctime>
#include <chrono>
#include <random>
#include <iostream>
#include <stdlib.h>

using namespace std;

void print(vector<int> a) {
    cout << "[";
    for (auto n: a) {
        cout << n << ",";
    }
    cout << "]" << endl;
}

void shuffle(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n ; i++) {
        int r = rand() % n;
        swap(a[i], a[r]);
    }
}

int main ()
{
    vector<int> array = {141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7};
    print(array);
    srand(time(0));
    shuffle(array);
    print(array);
    return 0;
}


