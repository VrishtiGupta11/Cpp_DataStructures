#include <iostream>
using namespace std;
#include <stack>

bool redundantBrackets(char* str) {
    stack<char> s1;
    int count = 0;
    for(int i=0; str[i] != '\0'; i++) {
        if(str[i] != ')' ) {
            s1.push(str[i]);
        }
        else {
            while(s1.top() != '(') {
                s1.pop();
                count++;
            }
            s1.pop();
            if(count <= 1) {
                return true;
            }
            else {
                count = 0;
            }
        }
        
    }
    return false;
}

int main() {
    char* str = new char[100];
    cin.getline(str, 100);
    cout << (redundantBrackets(str) ? "True" : "False");
}