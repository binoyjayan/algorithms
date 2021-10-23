
/*

Write a function that takes in a non-empty array of integers
and returns an array of the same length, where each element in
the output array is equal to the product of every other number
in the input array.

In other words, the value at output[i] is equal to the product
of every number in the input array other than input[i].

Note that you are expected to solve this problem without
using divison.

Sample input:

array = [5, 1, 4, 2]

Sample output:

[8, 40, 10, 20]

*/

#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> a) {
  // Write your code here.
    vector<int> prod(a.size(), 0);
    int product = 1;
    for(int i = 0; i < a.size(); i++) {
        prod[i] = product;
        product *= a[i];
    }
    
    product = 1;
    for(int i = a.size() - 1; i >= 0; i--) {
        prod[i] *= product;
        product *= a[i];
    }    
    
  return prod;
}

