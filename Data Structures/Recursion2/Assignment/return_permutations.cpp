#include <iostream>
using namespace std;

// Approach 1  -->  Consider 1st element as starting element, then consider 2nd element as the starting element, similarly each character as the starting element.
int ReturnPermutations(string str, string output[]) {
    string result[100];
    if(str.length() == 0) {
        output[0] = "";
        return 1;
    }
    int smallAns = 0;
    int size = str.length();
    for(int i=0; i<size; i++) {
        smallAns = ReturnPermutations(str.substr(0, i)+str.substr(i+1, size), result);
        for(int j=0; j<smallAns; j++) {
            output[smallAns*i+j] = str[i] + result[j];
        }
    }
    return smallAns*size;
}

// Approach 2  -->  find the permutations with recursion and add first element at every position 1 by 1.
int ReturnPermutations2(string str, string output[]) {
    string result[100];
    if(str.length() == 0) {
        output[0] = "";
        return 1;
    }
    int smallAns = ReturnPermutations2(str.substr(1), result);
    int k = 0;
    for(int i=0; i<smallAns; i++) {
        for(int j=0; j<str.length(); j++) {
            output[k++] = result[i].substr(0, j) + str[0] + result[i].substr(j, str.length());
        }
    }
    return smallAns*str.length();
}

int main() {
    string str, output[100];
    int outputSize;
    cin >> str;
    // outputSize = ReturnPermutations(str, output);
    outputSize = ReturnPermutations2(str, output);
    for(int i=0; i<outputSize; i++)
        cout << output[i] << endl;
}