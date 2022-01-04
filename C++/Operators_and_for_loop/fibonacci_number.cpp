#include<iostream>
using namespace std;

int main(){
    int previous = 1, current = 1, next, N;
    cin>>N;
    for(int i = 2; i < N; i++){
        next = previous + current;
        previous = current;
        current = next;
    }
    cout<<next<<endl;
    return 0;
}