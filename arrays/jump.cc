#include <iostream>
#include <vector>


/*
 * Kadane's algorithm
 */

// Print vector
void print_vector(const std::string s, const std::vector<int>& nums, int len) {
    std::cout << s << " [";
    for (int i = 0; i < len; i++) {
        std::cout << nums[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

bool canJump(std::vector<int>& nums) {
    int n = nums.size();
    int max_reach = 0;
    for (int i = 0; i < n; i++) {
        if (i > max_reach) {
            return false;
        }
        max_reach = std::max(max_reach, i + nums[i]);
        if (max_reach >= n - 1) {
            return true;
        }
    }
    return false;
}

// Minimum number of jumps to reach the end of the array
bool jump1(std::vector<int>& nums) {
    int n = nums.size();
    int max_reach = 0;
    for (int i = 0; i < n; i++) {
        if (i > max_reach) {
            return false;
        }
        max_reach = std::max(max_reach, i + nums[i]);
        if (max_reach >= n - 1) {
            return true;
        }
    }
    return false;
}

// Minimum number of jumps to reach the end of the array
int jump2(std::vector<int>& nums) {
    int n = nums.size();
    int max_reach = 0, curr_reach = 0, jumps = 0;
    for (int i = 0; i < n - 1; i++) {
        max_reach = std::max(max_reach, i + nums[i]);
        if (i >= curr_reach) {
            jumps++;
            curr_reach = max_reach;
        }
    }
    return jumps;
}


int main() {
    std::vector<int> nums = {2, 3, 1, 1, 4};
    print_vector("Stock prices", nums, nums.size());
    int min1 = jump1(nums);
    int min2 = jump2(nums);
    std::cout << "Min jumps:" << min1 << std::endl;
    std::cout << "Min jumps:" << min2 << std::endl;
}
