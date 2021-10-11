
/*
Given two non-empty array of integers, write a function that determines
whether the second array is a subsequence of the first one.

input:

array = [5, 1, 22, 25, 6, -1, 8, 10]
subsequence = [1, 6, -1., 10]

output:

true

*/

#include <unordered_set>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {    
    int i = 0, j = 0;
    
  while (i < array.size() && j < sequence.size()) {
        if (array[i] == sequence[j]) {
            j++;
    }
        i++;
    }        
  return j == sequence.size();
}

