#include<iostream>
using namespace std;

int main(){
    int N, i = 1;
    cout<<"Enter N: ";
    cin>>N;
    while (i<=N)
    {
        int j=1, k=i;
        while (j<=i)
        {
            cout<<k;
            j++;
            k++;
        }
        i++;
        cout<<endl;
    }
    
}