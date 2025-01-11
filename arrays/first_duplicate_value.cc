
/*

Given an array of integers between 1 and n, inclusive, where
n is the length of the array, write a function that returns
the first integer that appears more than once (when the array
is read from left to right).

In other words, out of all the integers that might occur more
than once in the input array, your function should return the
one whose first duplicate value has the minimum index.

If no integers more than once, your function should return -1.

Note that you are allowed to mutate the input array.

Sample input:

array = [2, 1, 5, 2, 3, 3, 4]

Sample outut:

2

// 2 is the first integer that appears more than once.
// 3 also appears more than once, but th second 3 appears 
// after the second 2.

*/

#include <vector>
using namespace std;

int firstDuplicateValue(vector<int> a) {
    int n = -1;
    for (int i = 0; i < a.size(); i++) {
        int index = abs(a[i]);
        if (a[index - 1] < 0)
            return index;
        a[index - 1] *= -1;
    }
    return -1;
}

