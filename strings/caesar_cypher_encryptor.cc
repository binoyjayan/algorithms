#include <string>
#include <iostream>
using namespace std;

string caesarCypherEncryptor(string str, int key) {
  // Write your code here.
    for (int i = 0; i < str.size(); i++) {
        int c = str[i] + key % 26;
        cout << "c: " << c << endl;
        if (c > 'z')
            c = 'a' + (c - 'z' - 1);
        cout << "c: " << c << endl;
        str[i] = c;
    }
  return str;
}

int main()
{
    // string a = "ovmqkwtujqmfkao";  int key = 52;
    string a = "xyz";  int key = 2;
    cout << caesarCypherEncryptor(a, key) << endl;
    return 0;
}




