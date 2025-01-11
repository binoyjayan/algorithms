/*
 * Write a function that takes a non-empty array of distinct integers
 * and an integer representing a target sum. The function should find
 * all triplets in the array that sum upto the target sum and return
 * a 2D array array of these triplets. The numbers in each triplet
 * should be ordered in ascending order.
 * 
 * Sample input:
 * array: [12, 3, 1, 2, -6, 5, -8 , 6]
 * target sum: 0
 * Sample output:
 *  [[-8, 2, 6], [-8, 3, 5], [-6, 1, 5]]
 */

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  sort(array.begin(), array.end());
    vector<vector<int>> triplets;
    for (int i = 0; i < array.size() - 2; i++) {
        int left = i + 1;
        int right = array.size() - 1;
        while (left < right) {
            int sum = array[i] + array[left] + array[right];
            if (sum == targetSum) {
                triplets.push_back({array[i], array[left], array[right]});
              left++;
              right--;
            } else if (sum < targetSum) {
                left++;
            } else {
                right--;
      }
    }
  }
  return triplets;
}

