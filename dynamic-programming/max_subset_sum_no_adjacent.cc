
/*

Write a function that takes in an array of +ve integers and returns
the maximum sum of non-adjacent elements in the array.


array = [75, 105, 120, 75, 90, 135]
sum: 330

*/

#include <vector>
using namespace std;

// Dynamic programming

int maxSubsetSumNoAdjacent(vector<int> a) {
    if (a.size() == 0) {
        return 0;
    } else if (a.size() == 1) {
        return a[0];
    }
    int n1 = a[0];
    int n2 = max(a[0], a[1]);
    for (int i = 2; i < a.size(); i++) {
        // maxsum[i] = max(maxsum[i-1], maxsum[i - 2] + a[i])
        int curr = max(n2, n1 + a[i]);
        n1 = n2;
        n2 = curr;
    }
  return n2;
}


