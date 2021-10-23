
/*/

Given an array of +ve integers representing coin denominations and a single
non-negative integer n representing a target amount of money, write a function
that returns the smallest number of coins needed to amke change for(to sum upto)
that target amount using the given coin denominations.

Note that you have access to an unlimited amount of coins. In other words, if the
denominations are [1, 5, 10], you have access to an unlimited amount of 1's 5's and 10's.


Sample input:
n = 7
denoms = [1, 5, 10]

Sample output: 3

*/

#include <vector>
#include <climits>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
  vector<int> coins(n + 1, INT_MAX);
    coins[0] = 0; // no coins needed to make $0
    for (int denom: denoms) {
        for (int amount = 0; amount < coins.size(); amount++) {
            // we can't use a denom if its greater than amount
            if (denom <= amount) {
                int prev = coins[amount - denom];
                if (prev == INT_MAX)                          //avoid overflow
                    coins[amount] = min(coins[amount], prev);
                else
                    coins[amount] = min(coins[amount], prev + 1);
            }            
        }
    }
  return coins[n] != INT_MAX? coins[n]:  -1;
}


