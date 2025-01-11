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

// Function that takes in a non-empty array of integers
// and returns the maximum sum that can be obtained by summing
// up all of the integers in a non-empty subarray of the i/p array.
int maxSum(std::vector<int> array) {
  int maxEndingHere = array[0];
    int maxSoFar = array[0];
    for (int i = 1; i < array.size(); i++) {
        int num = array[i];
        maxEndingHere = std::max(num, maxEndingHere + num);
        maxSoFar = std::max(maxSoFar, maxEndingHere);
  }
  return maxSoFar;
}


// Function that calculates the maximum profit that can be made from buying and selling a stock.
// Given an array prices where prices[i] is the price of a given stock on the ith day,
// return the maximum profit you can achieve from this transaction.
// Maximize your profit by choosing a single day to buy one stock and
// choosing a different day in the future to sell that stock.
// Return 0 when no profit can be made.
int maxProfit(std::vector<int>& prices) {
    int max_profit = 0;
    int min_price = prices[0];
    for (int i = 1; i < prices.size(); i++) {
        min_price = std::min(min_price, prices[i]);
        max_profit = std::max(max_profit, prices[i] - min_price);
    }
    return max_profit;
}

int main() {
    std::vector<int> nums = {2, 3, 4, 1, 5, 6, 7};
    print_vector("Stock prices", nums, nums.size());
    int max_profit = maxProfit(nums);
    int max_sum = maxSum(nums);
    std::cout << "Max Profit : " << max_profit << std::endl;
    std::cout << "Max Sum    : " << max_sum << std::endl;
}
