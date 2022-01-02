#include<iostream>
using namespace std;

int main(){
    int i=1, N;
    cin>>N;
    while(i <= N/2 + 1){
        int j = 1, k = 1, l = 1;
        while (j <= N/2 + 1 -i)
        {
            cout<<" ";
            j++;
        }
        while (k <= i)
        {
            cout<<"*";
            k++;
        }
        while(l <= i-1)
        {
            cout<<"*";
            l++;
        }
        cout<<endl;
        i++;
    }
    i = 1;
    while (i <= N/2)
    {
        int j = 1, k = 1, l = N/2-i;
        while (j <= i)
        {
            cout<<" ";
            j++;
        }
        while (k <= N/2 - i + 1)
        {
            cout<<"*";
            k++;
        }
        while (l >= 1)
        {
            cout<<"*";
            l--;
        }
        cout<<endl;
        i++;
    }
    return 0;
}