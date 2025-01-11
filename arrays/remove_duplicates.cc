#include <iostream>
#include <vector>

/*
Given an array of integers write a function that removes
duplicates in-place.
The relative order of the elements should be kept the same.
Also, return the number of unique elements in arr.
The resultant array may contain non-unique elements at the end.
*/

void print_vector(const std::string s, const std::vector<int>& nums, int len) {
    std::cout << s << " [";
    for (int i = 0; i < len; i++) {
        std::cout << nums[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

int removeDuplicates(std::vector<int>& nums) {
        int k = 1;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[k - 1] != nums[j]) {
                nums[k++] = nums[j];
            }
        }
        return nums.size() ? k : 0;
}

/// Remove duplicates from the array.
/// The unique elements can appear atmost twice in the result.
int removeDuplicatesAtMost2(std::vector<int>& nums) {
    int k = 1;
    int count = 1;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[k - 1] == nums[j]) {
            count++;
        } else {
            count = 1;
        }
        if (count <= 2) {
            nums[k++] = nums[j];
        }
    }
    return nums.size() ? k : 0;
}

int main() {
    std::vector<int> nums1 = {1, 2, 2, 3, 3, 4, 4, 4 };
    print_vector("LIST1         ", nums1, nums1.size());
    int n1 = removeDuplicates(nums1);
    print_vector("REMOVE DUP    ", nums1, n1);

    std::vector<int> nums2 = {1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 5};
    print_vector("LIST2         ", nums2, nums2.size());
    int n2 = removeDuplicatesAtMost2(nums2);
    print_vector("REMOVE ATMOST2", nums2, n2);
}


