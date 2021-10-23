
/*

Write a function that takes in an array of integers and returns
a boolean representing whether the array is monotonic.

An array is used to be monotonic if it elements, from left to
right are entirelt non-increasing or entirely non-decreasing.

Non-increasing elements aren't necessarily exclusively decreasing;
they simply do not increase. Similarly, non-decreasing elements
aren't necessarily increasing; they simply do not decrease.

Note that empty arrays and arrays with one element are monotonic.

Sample input:

array = [-1, -5, -10, -1100, -1100, -1101, -1102, -9001]

Sample ouput:

true

*/

using namespace std;

bool isMonotonic(vector<int> a) {
  // Write your code here.
    if (a.size() <= 1)
        return true;
    bool non_inc = true, non_dec = true;
    for(int i = 1; i < a.size() ; i++) {
         if (a[i - 1] > a[i])
                non_inc = false;
          if (a[i - 1] < a[i])
                non_dec = false;
    }
  return non_inc || non_dec;
}

