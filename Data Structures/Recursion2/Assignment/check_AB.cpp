#include <iostream>
using namespace std;

bool CheckAB(string str) {
    if(str.size() == 0)
        return true;
    if(str[0] == 'a') {
        if(str.substr(1).length() > 1 && str.substr(1, 3) == "bb")
            return CheckAB(str.substr(3));
        else
            return CheckAB(str.substr(1));
    }

    return false;
}

int main() {
    string str;
    cin >> str;
    if(CheckAB(str))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}