#include<iostream>
using namespace std;

int main(){
    int i=1, N;
    cin>>N;
    while (i <= N)
    {
        int j = 1, k = 1, m = i-1;
        while(j <= N-i){
            cout<<" ";
            j++;
        }
        while (k <= i)
        {
            cout<<i+k-1;
            k++;
        }
        while (m >= 1)
        {
            cout<<i+m-1;
            m--;
        }
        cout<<endl;
        i++;
    }
    return 0;
}