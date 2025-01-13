#include<string>
#include<vector>
#include<iostream>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    std::string prefix;
    bool matches = true;

    // idx represents the offset of how far we can go in all
    // of the string to get a common prefix.
    for(int idx = 0; matches ; idx++) {
        if (idx >= strs[0].length()) {
            break;
        }
        char curr = strs[0][idx];
        for (int j = 1; j < strs.size(); j++) {
            if (strs[j][idx] != curr) {
                matches = false;
                break;
            }
        }
        if (matches) {
            prefix += curr;
        }
    }

    return prefix;
}

int main() {
    // std::vector<std::string> strings = {""};
    std::vector<std::string> strings = {"flower", "flow", "flight"};
    auto prefix = longestCommonPrefix(strings);
    std::cout << "Prefix:" << prefix << "." << std::endl;
    return 0;
}