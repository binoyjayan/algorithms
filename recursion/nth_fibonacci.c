
/*

Write a function that takes in an integer n and returns the
nth Fibonacci number.

*/

using namespace std;

int getNthFib(int n) {
  // Write your code here.
    if (n == 1)
        return 0;
    int a = 0;
    int b = 1;
    int c;
    while (--n > 0) {
        a = b;
        b = c;
        c = a + b;
    }
  return c;
}


