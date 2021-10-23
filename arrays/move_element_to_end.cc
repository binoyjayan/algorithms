
/*

You,re given an array of integers and an integer. Write a function that
moves all instances of that integer in the array to the end of the array
and returns the array.

The function should perform this in place. (i.e. it should mutate the
input array) and doessn't need to maintain the order of the other integers.

Sample input:
array = [2, 1, 2, 2, 2, 3, 4, 2]
toMove = 2

Sample output:
[1, 3, 4, 2, 2, 2, 2, 2]
// numbers 1, 3 and 4 could be ordered.


*/



#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> a, int toMove) {
  // Write your code here.
    int n = a.size() - 1;
    for (int i = 0; i <= n;) {
        if (a[i] == toMove) {
            swap(a[i], a[n--]);
        } else {
            i++;
        }
    }
  return a;
}

