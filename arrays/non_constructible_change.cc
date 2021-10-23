
/*
 * Given an array of +ve integers representing the value of coins
 * in your posession, write a function that returns the minimum
 * amount of change that you cannot create.
 * e.g. 
 * sample input: [1, 2, 5]
 * sample output: 4
 */

#include <vector>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
  sort(coins.begin(), coins.end());
    int sum = 0;
    for(int i = 0; i < coins.size(); i++) {
        if (coins[i] > sum + 1)
            return sum + 1;
        sum += coins[i];
    }
  return sum + 1;
}

