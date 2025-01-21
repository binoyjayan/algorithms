#include<string>
#include<vector>
#include<iostream>
#include <unordered_set>

// Find the length of longest substring without repeating characters
// Uses a sliding window approach. The index to the longest substring
// is represented by the indices 'left' and 'right'.
// Time: O(n), Space: O(n)
int lengthOfLongestSubstring1(std::string s) {
    int left = 0;
    int max_length = 0;
    std::unordered_set<char> char_set;
    
    for (int right = 0; right < s.size(); right++) {
        while(char_set.find(s[right]) != char_set.end()) {
            // character pointed to by 'left' can no longer be considered
            char_set.erase(s[left]);
            // remove from sliding window
            left++;
        }
        char_set.insert(s[right]);
        max_length = std::max(max_length, right - left + 1);
    }

    return max_length;
}

// Find the length of longest substring without repeating characters
// Similar to the above algorithm except for the charset being represented
// as the indices of elements of characters in the symbol set [a-zA-Z0-9 ]
// No other characters are supported
int lengthOfLongestSubstring2(std::string s) {
    int left = 0;
    int max_length = 0;
    int char_idx[128];
    std::fill(char_idx, char_idx + 128, -1);

    for (int right = 0; right < s.size(); right++) {
        // Check if the current character has occurred within the current
        // substring by comparing its index in char_idx with left. If the
        // character has occurred again, its index is greater than 'left'
        // If so, move the left pointer to the next position after the last
        // occurrence of the character.
        if(char_idx[s[right]] >= left) {
            left = char_idx[s[right]] + 1;
        }
        // Record the index of the last occurence of character 's[right]'
        char_idx[s[right]] = right;
        max_length = std::max(max_length, right - left + 1);
    }

    return max_length;
}

int main() {
    // std::string s = "bbbbb";
    // std::string s = "pwwkew";
    std::string s = "abcabcbb";
    auto num1 = lengthOfLongestSubstring1(s);
    auto num2 = lengthOfLongestSubstring1(s);
    std::cout << "String:" << s << std::endl;
    std::cout << "Longest Substring length:" << num1 << std::endl;
    std::cout << "Longest Substring length:" << num2 << std::endl;
    return 0;
}