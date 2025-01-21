
/*

Write a function that returns a boolean representing whether
the input string is a palindrome.
*/

// #include <ctype.h>
#include <iostream>

bool isPalindrome(std::string str) {
    int n = str.size();
    for (int i = 0; i < n / 2 ; i++) {
        if (str[i] != str[n - i - 1])
            return false;
    }
    return true;
}

// Check for Palindrom string by ignoring case and all
// non-alphanumeric characters
bool isPalindromeAlphaNumeric(std::string s) {
    int i = 0, n = s.size() - 1;
    while (i <= n) {
        while (i <= n && !isalnum(s[i])) i++;
        while (i <= n && !isalnum(s[n])) n--;
        if (i > n) break;
        char c1 = tolower(s[i]);
        char c2 = tolower(s[n]);
        if (c1 != c2) return false;
        i++;
        n--;
    }
    return true;
}

int main() {
    std::string s1 = "radar";
    std::string s2 = "A man, a plan, a canal: Panama";
    std::string s3 = "race a car";
    std::cout << std::endl << "isPalindrome():" << std::endl;
    std::cout << "Str:" << s1 << ": " << isPalindrome(s1) << std::endl;
    std::cout << "Str:" << s2 << ": " << isPalindrome(s2) << std::endl;
    std::cout << "Str:" << s3 << ": " << isPalindrome(s3) << std::endl;

    std::cout << std::endl  << "isPalindromeAlphaNumeric():" << std::endl;
    std::cout << "Str:" << s1 << ": " << isPalindromeAlphaNumeric(s1) << std::endl;
    std::cout << "Str:" << s2 << ": " << isPalindromeAlphaNumeric(s2) << std::endl;
    std::cout << "Str:" << s3 << ": " << isPalindromeAlphaNumeric(s3) << std::endl;
    return 0;
}