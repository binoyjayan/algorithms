
/*

Write a function that, given a string, returns its longest palindrome substring.

*/

using namespace std;

vector<int> getLongestFrom(string str, int l, int r) {
    while (l >= 0 && r < str.length()) {
        if (str[l] != str[r]) break;
        l--; r++;
    }
    return vector<int> {l + 1, r};
}

string longestPalindromicSubstring(string str) {
    vector<int> currLong = {0, 1};
    for (int i = 1; i < str.length(); i++) {
        vector<int> odd = getLongestFrom(str, i - 1, i + 1);
        vector<int> even = getLongestFrom(str, i - 1, i);
        vector<int> longest = odd[1] - odd[0] > even[1] - even[0]? odd: even;
        currLong = currLong[1] - currLong[0] > longest[1] - longest[0]?
                     currLong: longest;
    }
  return str.substr(currLong[0], currLong[1] - currLong[0]);
}


