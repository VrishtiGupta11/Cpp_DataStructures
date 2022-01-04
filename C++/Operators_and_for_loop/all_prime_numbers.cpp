#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    
    cout<<"2\n";
    for(int i=3; i<=N; i++){
        bool divided = false;
        for(int j=2; j<=i/2; j++){
            if(i%j == 0){
                divided = true;
                break;
            }
        }
        if(!divided){
            cout<<i<<endl;
        }
    }
    return 0;
}