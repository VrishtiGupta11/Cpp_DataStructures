#include<iostream>
using namespace std;

int main(){
    int N, i = 1;
    cout<<"Enter N: ";
    cin>>N;
    while (i<=N)
    {
        int j=1;
        while (j<=N-i)
        {
            cout<<" ";
            j++;
        }
        int k=1;
        while (k<=i)
        {
            cout<<"*";
            k++;
        }
        int l=2;
        while (l<=i)
        {
            cout<<"*";
            l++;
        }
        i++;
        cout<<endl;
    }
    
}