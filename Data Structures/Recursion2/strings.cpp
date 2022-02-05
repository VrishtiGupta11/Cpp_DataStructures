#include <iostream>
#include <string>
using namespace std;

int main() {
    // string s1 = "abc";
    // string s2 = "Vrishti";
    // cout << s1 << endl;
    // cout << s2 << endl;

    // We can use getline(cin, str) with str of type string as for this we cannot use cin.getline as that uses char[] type variable.
    
    // string str, str1;
    // // cin >> str;
    // // cin.getline(str); // error as object of string data type can not be passed
    // getline(cin, str);
    // cout << str <<endl;
    // getline(cin, str1);
    // cout << str1 << endl;

    // char s1[10], s2[10];
    // cin.getline(s1, 20);
    // // cin >> s1;
    // cout << s1 << endl;
    // // cin.getline(s2, 20);
    // cin >> s2;
    // cout << s2 << endl;

    // Dynamic String allocation.

    // string* sp = new string;
    // getline(cin, *sp);
    // cout << *sp;

    // String Concatenation

    // string s1 = "abc";
    // string s2 = "-";
    // string s3 = "xyz";

    // s1 += s2+s3;
    // cout << s1 << endl;

    // Some Inbuilt functions on strings of type String.
    string s = "abcdef";
    cout << s.size() << endl;
    cout << s.length() << endl;
    cout << s.substr(2) << endl;
    cout << s.substr(2, 3) << endl;
    cout << s.find("de") << endl;

}