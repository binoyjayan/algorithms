#include <iostream>
#include <vector>

/*

Given an array of distinct +ve integers representing coin denominations
and a single non-negative integer n representing a target amount of money,
write a function that returns the number of ways to make change for tha
target amount using the given coin denominations.

Assume an unlimited supply of coins.

Sample input:
n = 6
denoms = [1, 5]

Sample output:

2
*/

#include <vector>
#include <iomanip>
using namespace std;

void print_header(const std::string s, int len) {
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << s << " [";
    for (int i = 0; i < len; i++) {
        std::cout << std::setw(3) << i << ", ";
    }
    std::cout << "]" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
}

// Print vector
void print_vector(const std::string s, const std::vector<int>& nums, int len) {
    std::cout << s << " [";
    for (int i = 0; i < len; i++) {
        std::cout << std::setw(3) << nums[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

// Find the number of ways to make change for a given amount
// Divide the problem into subproblems. The sub problem is to
// find the number of ways to make change for sub-amounts.
// To calculate ways[amount], the sub-problem is to add
// ways[amount - denom] to ways[amount] that was calulated
// for the previous denomination.
int numberOfWaysToMakeChange(int n, vector<int> denoms) {
    vector<int> ways(n + 1, 0);
    // Only one way to make '0' cents
    ways[0] = 1;
    for (auto denom: denoms) {
        std::cout << "Denom = " << denom << ":" << std::endl;
        for (int amount = 1; amount <= n; amount++) {
            if (denom <= amount) {
                ways[amount] += ways[amount - denom];
                print_vector("ways   ", ways, ways.size());
            }
        }
  }
  return ways[n];
}

int main() {
    int n = 6;
    std::vector<int> denoms = {1, 3};
    print_vector("Denoms", denoms, denoms.size());
    print_header("Amounts", n + 1);
    int ways = numberOfWaysToMakeChange(n, denoms);
    std::cout << "Number of ways to make change for " << n << " = " << ways << std::endl;
}

