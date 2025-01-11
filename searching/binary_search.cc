
/*

Write a function that takes in a target integer and
searches it in an sorted array.
*/

#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target) {
  // Write your code here.
    int start = 0;
    int end = array.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (array[mid] > target) {
            end = mid - 1;
        } else if (array[mid] < target) {
            start = mid + 1;
        } else {
            return mid;
        }
    }
  return -1;
}


