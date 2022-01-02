#include<iostream>
using namespace std;

int main(){
    int i=1, N;
    cin>>N;
    while (i<=N)
    {
        int j = 1;
        while (j <= N-i+1)
        {
            cout<<N-i+1;
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}