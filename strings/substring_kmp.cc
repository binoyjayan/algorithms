/*
 * Knuth-Morris-Pratt sub-string search algorithm
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// Complexity: O(m + n) time, O(m) space
vector<int> build_pattern(string substr) {
    // Initialize the pattern with '-1'
    vector<int> pattern(substr.length(), -1);
    int j = 0;
    int i = 1;

    while (i < substr.length()) {
        if (substr[i] == substr[j]) {
            pattern[i] = j;
            i++;
            j++;
        } else if (j > 0) {
            // next letter after the previous prefix = suffix match
            j = pattern[j - 1] + 1;
        } else {
            i++;
        }
    }
    return pattern;
}

// Return index of substr in str
int find(string str, string substr, vector<int> pattern) {
    int i = 0;
    int j = 0;
    while (i + substr.length() - j <= str.length()) {
        if (str[i] == substr[j]) {
            if (j == substr.length() - 1) {
                return i - substr.length() + 1;
            }
            i++;
            j++;
        } else if (j > 0) {
            j = pattern[j - 1] + 1;
        } else {
            i++;
        }
    }
    return -1;
}

int search(string str, string substr) {
  vector<int> pattern = build_pattern(substr);
  return find(str, substr, pattern);
}

bool match(string text, string pattern) {
    int index = search(text, pattern);
    cout << "[" << text << ", " << pattern << "]: ";
    if (index < text.size()) {
        cout << "Match found at index " << index << endl;
        return true;
    }
    cout << "No match found" << endl;
    return false;
}

int main() {
    match("GCTTCTGCTACCT", "TGCT");
    match("GCTTCTGCTACCT", "CCTTTTGC");
    return 0;
}
