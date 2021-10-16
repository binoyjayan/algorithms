/*
 * Boyer Moore sub-string search algorithm
 */
#include <string>
#include <iostream>
using namespace std;

#define R 256

/*
 * The 'right' array has the index to the rightmost occurrence
 * of each character in 'pattern' or '-1' for the rest of the
 * character set. This value tells us precisely how far to skip
 * if that character appears in text and causes a mismatch during
 * the string search. This function helps build the array based
 * the bad character rule.
 *
 * Bad character rule: Upon mismatch skip alignments until:
 * 1. Mismatch becomes a match
 * 2. Pattern (P) moves past the mismatched character
 *
 * e.g.
 *      T: GCTTCTGCTACCT
 *      P: CCTTTTGC
 * offset: 01234567
 * Here, while trying to match a 'C' at offset '4',
 *  we find a bad character 'T' in the pattern.
 *  Next match for the character 'C' is at offset '1'
 *  skip 3 steps until the mismatch becomes a match(at offset '1'
 */
void bad_char_heuristic(string pattern, int right[R]) {
    for (int i = 0; i < R; i++) {
        right[i] = -1;
    }
    int M = pattern.size();
    // Fill values for last occurrence of a character
    for (int i = 0; i < M; i++) {
        right[pattern[i]] = i;
    }
}

// O(N/M) time
int search(string text, string pattern) {
    int M = pattern.size();
    int N = text.size();
    int right[R];
    int skip = 0;

    for (int i = 0; i < N - M; i += skip) {
        // Does the pattern match the text at position 'i'?
        skip = 0;
        for (int j = M - 1; j >= 0; j--) {
            if (pattern[j] != text[i + j]) {
                // 1 is to avoid backtracking due to '-1' in 'right'
                skip = max(1, right[text[i + j]]);
                // skip 'skip' bytes and move on to index 'i + skip'
                break;
            }
        }
        if (skip == 0)
            return i; // Match found at 'i'
    }
    return N;
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




