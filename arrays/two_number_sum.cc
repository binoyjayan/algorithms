#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

/*
 * Write a function that takes a non-empty arrat of distinct integers
 * and an integer representing a target sum. If any two numbers in the
 * input array sum upto the target sum, then the functio should return
 * them in an array.
 */
vector<int> _twoNumberSum(vector<int> array, int targetSum) {
    unordered_set<int> nums;    
    for (int n : nums) {
        if (nums.find(targetSum - n) == nums.end()) {
            cout << "insert: " << n << endl;
            nums.insert(n);
        } else {
            return vector<int>{targetSum - n, n};
        }
  }
  return {};
}

vector<int> twoNumberSum(vector<int> array, int targetSum) {
    unordered_set<int> nums;
    for (const int &n : array) {
        if (nums.find(targetSum - n) != nums.end()) {
            return {targetSum - n, n};
        }
        else {
            nums.insert(n);
        }
  }
  return {};
}

void print_vector(vector<int> &vect) {
   cout << "[ ";
   for (auto v: vect) {
      cout << v << ", ";
   }
   cout << " ]" << endl;
}

int main() {
    vector<int> arr = {3, 5, -4, 8, 11, 1, -1, 6};
    vector<int> s = twoNumberSum(arr, 10);
    print_vector(s);
    return 0;
}

