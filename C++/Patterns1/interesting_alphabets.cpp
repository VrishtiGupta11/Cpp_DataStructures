#include<iostream>
using namespace std;

int main(){
    int i=1, N;
    cin>>N;
    while (i<=N)
    {
        int j = 1;
        char m = 'A' + N - i;
        while (j<=i)
        {
            cout<<m;
            j++;
            m++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}