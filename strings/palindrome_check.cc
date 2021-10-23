
/*

Write a function that returns a boolean representing whether
the input string is a palindrome.
*/

using namespace std;

bool isPalindrome(string str) {
  // Write your code here.
    int n = str.size();
    for (int i = 0; i < n / 2 ; i++) {
        if (str[i] != str[n - i - 1])
            return false;
    }
  return true;
}


