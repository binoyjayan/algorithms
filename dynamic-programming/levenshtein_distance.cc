
/*

Write a function that takes in two strings and returns the minimum
number of edit operations that need to be performed on the first
string to obtain the second string.

Sample input:

str1 = "abc"
str2 = "yabd"

Sample output:
2

*/

using namespace std;

// O(nm) time | O(nm) space
int _levenshteinDistance(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
  int edits[n + 1][m + 1];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            edits[i][j] = j;
        }
        edits[i][0] = i;
  }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str2[i - 1] == str1[j -1]) {
                edits[i][j] = edits[i -1][j - 1];
            } else {
                edits[i][j] = 1 + min(edits[i - 1][j - 1], min(edits[i-1][j], edits[i][j - 1]));
            }
        }
  }
  return edits[n][m];
}

// O(nm) time | O(min(n, m)) space
int levenshteinDistance(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    string small = m < n? str1: str2;
    string big = m >= n? str1: str2;
    int small_len = small.length();
    int big_len = big.length();
    int evenEdits[small_len + 1];
    int oddEdits[small_len + 1];
    
    for (int j = 0; j < small_len + 1; j++) {
        evenEdits[j] = j;
  }
    
    int *currEdits;
    int *prevEdits;
    for (int i = 1; i <= big_len; i++) {
        if (i % 2) {
            currEdits = oddEdits;
            prevEdits = evenEdits;
    } else {
            currEdits = evenEdits;
            prevEdits = oddEdits;
        }
        currEdits[0] = i;
        for (int j = 1; j <= small_len; j++) {
            if (big[i - 1] == small[j - 1]) {
                currEdits[j] = prevEdits[j - 1];
            } else {
                currEdits[j] = 1 + min(prevEdits[j - 1], min(prevEdits[j], currEdits[j -1]));
            }            
        }
  }
  return big_len % 2 == 0? evenEdits[small_len] : oddEdits[small_len];
}




