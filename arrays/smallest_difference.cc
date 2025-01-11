
/*

Write a function that takes in a two non-empty arrays of integers,
find the pair of numbers (one from each array) whose absolute
difference is closest to zero, and returns an array containing
these two numbers, with the number from the first array in
the first position.

Assume that there will only be on pair of numbers with the
smallest difference.

Sample input:

arrayOne = [-1, 5, 10, 20, 28, 3]
arrayTwo = [26, 134, 135, 15, 17]

Sample output:
[28, 26]

*/

#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  // Write your code here.
    vector <int> pair;
    sort(arrayOne.begin(), arrayOne.end());
    sort(arrayTwo.begin(), arrayTwo.end());
    int first, second, i = 0, j = 0;;
    int sum = INT_MAX, smallestSum = INT_MAX;
    while (i < arrayOne.size() && j < arrayTwo.size()) {
        first = arrayOne[i];
      second = arrayTwo[j];
        if (first < second) {
          sum = second - first;
            i++;
        } else if (first > second) {
            sum = first - second;
            j++;
    } else {
            pair = {first, second};
            break;
        }
        if (sum < smallestSum) {
            smallestSum = sum;
            pair = {first, second};
        }
  }
  return pair;
}

