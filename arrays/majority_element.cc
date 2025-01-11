#include <iostream>
#include <vector>

/*
Given an array of integers write a function that returns
the majority element in the array. The majority element
is the element that appears more than n/2 times.
*/

void print_vector(const std::string s, const std::vector<int>& nums, int len) {
    std::cout << s << " [";
    for (int i = 0; i < len; i++) {
        std::cout << nums[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

// Use Boyer-Moore Voting Algorithm to find the majority element
int majorityElement(std::vector<int>& nums) {
    int count = 0;
    int candidate = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        count += (nums[i] == candidate) ? 1 : -1;
    }
    return candidate;
}

int main() {
    std::vector<int> nums1 = {1, 2, 2, 3, 3, 4, 4, 4 };
    print_vector("LIST             ", nums1, nums1.size());
    int maj = majorityElement(nums1);
    std::cout << "Majority element " << maj << std::endl;
}


