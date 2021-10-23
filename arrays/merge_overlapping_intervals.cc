
/*

Write a function that takes in a non-empty array of arbitrary intervals,
merges any overlapping intervals, and returns the new intervals in no
particular order.

Each interval is an array of two integers, with interval[0] as the start
of the interval and interval[1] as the end of the interval.

Sample input:

[[1, 2], [3,5], [4, 7], 6, 8], [9, 10]]

Sample output:

[[1,2,], [3, 8], [9, 10]]

*/

#include <vector>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
  // Write your code here.
    vector<vector<int>> merged;
    vector<vector<int>> sorted = intervals;
    sort(sorted.begin(), sorted.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
    });
    
    int n = 0;
    merged.push_back(sorted[0]);
    for (int i = 1; i < sorted.size(); i++) {
        vector<int> interval = sorted[i];
        if (merged[n][1] >= interval[0]) {
            merged[n][1] = max(merged[n][1], interval[1]);
        } else {
            merged.push_back(interval);
            n++;
        }
    }
  return merged;
}


