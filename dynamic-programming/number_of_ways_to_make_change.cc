
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
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
    vector<int> ways(n + 1, 0);
    // Only one way to make '0' cents
    ways[0] = 1;
    for (auto denom: denoms) {
        for (int amount = 1; amount <= n; amount++) {
            if (denom <= amount) {
                ways[amount] += ways[amount - denom];
            }
        }
  }
  return ways[n];
}


