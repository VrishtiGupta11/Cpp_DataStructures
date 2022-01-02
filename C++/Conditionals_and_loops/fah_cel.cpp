#include<iostream>
using namespace std;

int main(){
    int S, E, W;
    cin>>S>>E>>W;
    while (S <= E)
    {
        cout<<S<<"\t"<<(5*(S-32))/9<<endl;
        S += W;
    }
    return 0;
}