#include<iostream>
using namespace std;

int main(){
    int N, i = 1;
    cout<<"Enter N: ";
    cin>>N;
    while (i<=N)
    {
        int j=1;
        while (j <= N-i)
        {
            cout<<" ";
            j++;
        }
        int m=1, k=i;
        while (m<=i)
        {
            cout<<k;
            m++;
            k++;
        }
        i++;
        cout<<endl;
    }
    
}