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

#include <set>
#include <vector>
#include <iomanip>
#include <iostream>
#include <unordered_set>
using namespace std;

void print_vector(const std::string s, const std::vector<int>& nums) {
    std::cout << s << " [";
    for (int i = 0; i < nums.size(); i++) {
        std::cout << std::setw(3) << nums[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

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

// Find distinct triplets that add up to a target sum of zero
vector<vector<int>> threeNumberSumDistinct(vector<int> nums) {
    sort(nums.begin(), nums.end());
    set<vector<int>> triplets;
    for (int i = 0; i < nums.size() - 2; i++) {
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                triplets.insert({nums[i], nums[left], nums[right]});
              left++;
              right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    vector<vector<int>> result(triplets.begin(), triplets.end());
    return result;
}


int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    print_vector("Numbers", arr);
    vector<vector<int>> triplets = threeNumberSum(arr, 0);
    for (auto v: triplets) {
        print_vector("3-Sum-to-Zero", v);
    }
    vector<vector<int>> triplets_dist = threeNumberSumDistinct(arr);
    for (auto v: triplets_dist) {
        print_vector("3-Sum-to-Zero-Distinct", v);
    }
    return 0;
}

