#include <iostream>
#include <vector>

/*
Given an array of integers write a function that rotates
the array to the right by k steps.
For example, given the array
[1, 2, 3, 4, 5, 6, 7] and k = 3, the result should be
[5, 6, 7, 1, 2, 3, 4].
*/

void print_vector(const std::string s, const std::vector<int>& nums, int len) {
    std::cout << s << " [";
    for (int i = 0; i < len; i++) {
        std::cout << nums[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

// Rotate the array to the right by k steps.
// This can be done by reversing the whole array,
// which moves the elements to the appropriate positions but in the wrong order.
// Then reverse the first k elements to fix the order of the first k elements.
// Finally, reverse the rest of the array to fix the order of the remaining elements.
void rotate(std::vector<int>& nums, int k) {
    k %= nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7 };
    print_vector("LIST        ", nums, nums.size());
    rotate(nums, 3);
    print_vector("Rotated List", nums, nums.size());
}
