#include <iostream>
using namespace std;

bool pallindrome(string str, int ind) {
    if(ind >= str.size()/2)
        return true;
    if(str[ind] != str[str.size()-ind-1])
        return false;
    pallindrome(str, ind+1);
}

int main() {
    string str;
    cin >> str;
    bool ispallindrome = pallindrome(str, 0);
    if(ispallindrome)
        cout << "Pallindrome" << endl;
    else
        cout << "Not Pallindrome" << endl;
}