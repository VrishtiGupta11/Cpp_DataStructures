#include<iostream>
using namespace std;

int main() {
    int N;
    cin>>N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<i; j++){
            cout<<" ";
        }
        cout<<i;
        for(int j=N-2*i+3; j >0; j--){
            cout<<" ";
        }
        if(i!=N)
            cout<<i;
        cout<<endl;
    }
    for(int i=1; i<N; i++){
        for(int j=1; j<N-i; j++)
            cout<<" ";
        cout<<N-i;
        for(int j = 1; j<=2*(i+1)-3; j++)
            cout<<" ";
        cout<<N-i;
        cout<<endl;
    }
}