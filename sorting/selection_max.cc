#include <vector>
#include <ctime>
#include <chrono>
#include <random>
#include <iostream>

using namespace std;

void swap(vector<int>&a, int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
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

void print(vector<int> a) {
    cout << "[";
    for (auto n: a) {
        cout << n << ",";
    }
    cout << "]" << endl;
}

int selection(vector<int> &a, int k) {
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

vector<int> findThreeLargestNumbers(vector<int> array) {
  // Write your code here.
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (array.begin(), array.end(), std::default_random_engine(seed));
    int n = array.size();
    int n1 = selection(array, n - 1);
    int n2 = selection(array, n - 2);
    int n3 = selection(array, n - 3);
    return {n1, n2, n3};
}

int main ()
{
    vector<int> array = {141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7};
    vector<int> a = findThreeLargestNumbers(array);
    print(array);
    print(a);
    return 0;
}

