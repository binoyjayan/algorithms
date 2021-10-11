#include <vector>
#include <iostream>
using namespace std;


/*
Write a function that takesin an array of integers and returns the
length of the longest peak in the array.

A peak is defined as adjacent integers in the arrat that are strictly
increasing until they reach a tip at which they become strictly decreasing.
Atleast three numbers are required to form a peak.
*/

void print(vector<int> a) {
    cout << "[";
    for (auto n: a) {
        cout << n << ",";
    }
    cout << "]" << endl;
}

int longestPeak(vector<int> a) {
    int len = 0;
    if (a.size() < 2)
      return 0;
    vector<int> peaks;
    // find all peak indices
    for (int i = 1; i < a.size() - 1; i++) {
        if (a[i - 1] < a[i] && a[i] > a[i+1])
            peaks.push_back(i);
    }
    if (peaks.size() < 1)
        return 0;

    print(a);
    print(peaks);
    cout << "peaks: " << peaks.size() << endl;
    
    // Calculate left and right lengths of all peaks and find the longest among them
    for (int k = 0; k < peaks.size(); k++) {
        int left = 0;
        int right = 0;
        cout << "[" << k << "] " << peaks[k] << ":" << a[peaks[k]] << endl;
        for (int i = peaks[k]; i > 0 && a[i-1] < a[i]; i--) {
            left++;
            cout << a[i - 1] << " < " << a[i] << " left:" << left << endl;
        }
        cout << "r: " << a[peaks[k]] << "," << a[peaks[k] + 1] << endl;
        for (int i = peaks[k]; i < a.size() - 1 && a[i] > a[i + 1]; i++) {
            right++;
          cout << a[i] << " > " << a[i + 1] << " right:" << right << endl;
        }
        int n = left + right + 1;
        cout << "n:" << n << endl;
        if (n > len)
            len = n;
  }
  return len;
}

int main() {
   vector<int> a = {1,2,3,3,4,0,10,6,5,-1,-3,2,3};
   int len = longestPeak(a);
   cout << "len:" << len << endl;
}





