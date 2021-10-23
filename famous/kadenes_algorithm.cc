
#include <vector>
using namespace std;


/* Kadane's algorithm
 * 
 * Write a function that takes in a non-empty array of integers
 * and returns the maxinum sum that can be obtained by summing
 * up all of the integers in a non-empty subarray of the i/p array.
 * The subarray must only have adjacent numbers.
 */


// O(n) time, O(1) space
int kadanesAlgorithm(vector<int> array) {
  int maxEndingHere = array[0];
    int maxSoFar = array[0];
    for (int i = 1; i < array.size(); i++) {
        int num = array[i];
        maxEndingHere = max(num, maxEndingHere + num);
        maxSoFar = max(maxSoFar, maxEndingHere);
  }
  return maxSoFar;
}

