/*
 * Write a function that takes in a non-empty array of integers
 * that are in sorted order and returns a new array of the same
 * length with the squares of the original integers also in
 * ascending order.
 */

 // sample input: [1,2,3,4,5,6]
 // sample output: [1, 4, 9, 16, 25, 36]

#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
    int i = 0;
    int j = array.size() - 1;
    int k = array.size() - 1;
    vector<int> squares(array.size(), 0);

    while (i <= j) {
        if (abs(array[i]) > abs(array[j])) {
            squares[k--] = array[i] * array[i];
            i++;
        } else {
            squares[k--] = array[j] * array[j];
            j--;
        }
  }
  return squares;
}

