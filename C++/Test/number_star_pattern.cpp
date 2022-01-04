#include<iostream>
using namespace std;

int main() {
    int i=1, N;
    cin>>N;
    while (i<=N)
    {
        int j=1;
        while(j <= N-i+1){
            cout<<j;
            j++;
        }
        int k=1;
        while(k <= i-1){
            cout<<"*";
            k++;
        }
        k=1;
        while(k <= i-1){
            cout<<"*";
            k++;
        }
        j=N-i+1;
        while(j >= 1){
            cout<<j;
            j--;
        }
        cout<<endl;
        i++;
    }
    return 0;
}