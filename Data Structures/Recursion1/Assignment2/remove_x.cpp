#include <iostream>
#include <cstring>
using namespace std;

int RemoveX(char str[], int size, char output[]) {
    if(size == 0)
        return 0;
    int smallAns = RemoveX(str, size-1, output);
    if(str[size-1] != 'x') {
        output[smallAns] = str[size-1];
        return smallAns+1;
    }
    return smallAns;
}

int main() {
    char str[1000], output[1000];
    cin >> str;
    output[RemoveX(str, strlen(str), output)] = '\0';
    cout << output;
}