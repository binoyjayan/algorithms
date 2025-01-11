#include <vector>
#include <iomanip>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*
 * Write a function that takes a non-empty arrat of distinct integers
 * and an integer representing a target sum. If any two numbers in the
 * input array sum upto the target sum, then the functio should return
 * them in an array.
 */

vector<int> twoNumberSum(vector<int> array, int targetSum) {
    unordered_set<int> nums;
    for (const int &n : array) {
        int other = targetSum - n;
        if (nums.find(other) != nums.end()) {
            return {other, n};
        }
        nums.insert(n);
    }
    return {};
}

std::vector<int> twoNumberSumIndices(const std::vector<int>& numbers, int targetSum) {
    std::unordered_map<int, int> indices;
    for (int i = 0; i < numbers.size(); ++i) {
        int other = targetSum - numbers[i];

        if (indices.find(other) != indices.end()) {
            if (indices[other] < i) {
                return {indices[other], i};
            } else {
                return {i, indices[other]};
            }
        }
        indices[numbers[i]] = i;
    }
    // not found
    return {};
}


void print_vector(const std::string s, const std::vector<int>& nums) {
    std::cout << s << " [";
    for (int i = 0; i < nums.size(); i++) {
        std::cout << std::setw(3) << nums[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    vector<int> arr = {2, 7, 11, 15};
    auto target = 9;
    print_vector("Numbers", arr);
    std::cout << "Target sum: " << target << std::endl;
    vector<int> s = twoNumberSum(arr, target);
    vector<int> indices = twoNumberSumIndices(arr, target);
    print_vector("Sum numbers", s);
    print_vector("Indices", indices);
    return 0;
}

