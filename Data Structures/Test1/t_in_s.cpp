#include <iostream>
#include <string>
using namespace std;

bool TinS(string s, string t) {
    if(t.length() == 0) 
        return true;
    else {
        if(s.length() == 0)
            return false;
    }
    if(s[0] == t[0]) 
        return TinS(s.substr(1), t.substr(1));
    else
        return TinS(s.substr(1), t);
}

int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);
    if(TinS(s, t))
        cout << "true";
    else 
        cout << "false";
}