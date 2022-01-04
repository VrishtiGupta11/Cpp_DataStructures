#include<iostream>
using namespace std;

int main() {
    int x, N=1;
    cin>>x;
    while (x > 0)
    {
        if((3*N + 2) % 4 == 0){
            N++;
            continue;
        }
        cout<<3*N + 2<<" ";
        N++;
        x--;
    }
    return 0;
}