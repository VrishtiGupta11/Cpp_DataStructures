#include<iostream>
using namespace std;

int main() {
    int number, i=1;
    cin>>number;
    while (i*i <= number) {
        i++;
    }
    cout<<i-1<<endl;
}