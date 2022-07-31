#include <iostream>
#include <unordered_map>
using namespace std;

string uniqueCharacters(string str) {
    string output = "";
    unordered_map<char, int> map;
    for(int i=0; i<str.length(); i++) {
        if(map.count(str[i]) == 0) {
            output += str[i];
            map[str[i]]++;
        }
    }
    return output;
}

int main() {
    string str;
    cin >> str;
    str = uniqueCharacters(str);
    cout << str << endl;
}