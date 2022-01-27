#include<iostream>
using namespace std;

void increment(int j){
    j++;
}

void decrement(int& j){
    j--;
}

int main() {
    int i = 10;
    int& j = i;
    cout<<j<<endl;
    increment(i);
    decrement(i);
    cout<<i<<" "<<j<<endl;
}