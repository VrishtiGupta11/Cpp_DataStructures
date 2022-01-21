#include<iostream>
using namespace std;

int main() {
    int N;
    cin>>N;
    int bh = (3*N)-2, lv=(N-1)*4, rv = N+1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i == 1)
                cout<<j<<"  ";
            else if(i == N)
                cout<<bh--<<" ";
            else if(j == 1)
                cout<<lv--<<" ";
            else if(j == N)
                cout<<rv++<<" ";
            else
                cout<<"   ";
        }
        cout<<endl;  
    }
}