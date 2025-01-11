#include <string>
#include <iostream>

using namespace std;

string runLengthEncoding(string str) {
    int c;
    string encoded;
    for (int i = 0; i < str.size(); i += c) {
        c = 1;
        while(c < 9 && str[i] == str[i + c]) {
          c++;
        }
        encoded.append(1, char(c + '0'));
        encoded.append(1, str[i]);
  }
  return encoded;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
      cout << "usage: " << argv[0] << " <string>\n";
      return 1;
    }
    string a = argv[1];
    cout << runLengthEncoding(a) << endl;
    return 0;
}
