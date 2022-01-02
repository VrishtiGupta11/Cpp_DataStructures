#include<iostream>
using namespace std;

int main(){
    int i=1, N;
    cin>>N;
    while (i<=N)
    {
        int j=1, k=1;
        while(j <= N-i)
        {
            cout<<" ";
            j++;
        }
        while (k <= i)
        {
            cout<<k;
            k++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}