#include<iostream>
using namespace std;

int CountZeros(int number) {
    if (number == 0)
        return 0;
    int smallAns = CountZeros(number/10);
    if(number % 10 == 0) 
        return smallAns+1;
    return smallAns;
}

int main() {
    int number;
    cin >> number;
    cout << CountZeros(number);
}