
/*
 * Convert Roman to integers
*/

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

int romanToInt(std::string s) {
    // Use a large enough character set for roman numerals
    int roman_values[128] = {};
    roman_values['I'] = 1;
    roman_values['V'] = 5;
    roman_values['X'] = 10;
    roman_values['L'] = 50;
    roman_values['C'] = 100;
    roman_values['D'] = 500;
    roman_values['M'] = 1000;

    int total = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        // Check if the current numeral is smaller than the next
        if (i + 1 < s.length() && roman_values[s[i]] < roman_values[s[i + 1]]) {
            total -= roman_values[s[i]];
        } else {
            total += roman_values[s[i]];
        }
    }
    return total;
}

std::string intToRoman(int num) {
    std::vector<std::pair<int, std::string>> roman_map = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, 
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, 
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    std::string result;
    // Exhaust the largest roman character set first
    for (const auto& mapping : roman_map) {
        int value = mapping.first;
        const std::string& symbol = mapping.second;

        while (num >= value) {
            result += symbol;
            num -= value;
        }
    }

    return result;
}

int main() {
    std::string orig_s1 = "III";
    std::string orig_s2 = "IV";
    std::string orig_s3 = "IX";
    std::string orig_s4 = "LVIII";
    std::string orig_s5 = "MCMXCIV";

    auto n1 = romanToInt(orig_s1);
    auto n2 = romanToInt(orig_s2);
    auto n3 = romanToInt(orig_s3);
    auto n4 = romanToInt(orig_s4);
    auto n5 = romanToInt(orig_s5);
q
    auto s1 = intToRoman(n1);
    auto s2 = intToRoman(n2);
    auto s3 = intToRoman(n3);
    auto s4 = intToRoman(n4);
    auto s5 = intToRoman(n5);

    std::cout << orig_s1 << ": " << n1 << ": " << s1 << std::endl;
    std::cout << orig_s2 << ": " << n2 << ": " << s2 << std::endl;
    std::cout << orig_s3 << ": " << n3 << ": " << s3 << std::endl;
    std::cout << orig_s4 << ": " << n4 << ": " << s4 << std::endl;
    std::cout << orig_s5 << ": " << n5 << ": " << s5 << std::endl;

    return 0;
}
