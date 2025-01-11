
/*

Write a function that takes in a string of lowercase english alphabet
and returns the index of the string's first non-repeating chacaters.

*/

using namespace std;

int firstNonRepeatingCharacter(string string) {
  // Write your code here.
    map<char, int> chars;
    for (int i = 0; i < string.size(); i++) {
        char ch = string[i];
        if (chars.find(ch) != chars.end()) {
            chars[ch] = -1;
    } else {
          chars.insert({ch, i});
        }
    }
    for (int i = 0; i < string.size(); i++) {
        char ch = string[i];
        if (chars[ch] != -1)
            return chars[ch];
    }
  return -1;
}


