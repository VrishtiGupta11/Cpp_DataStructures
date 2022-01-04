#include<iostream>
using namespace std;

int main() {
    int i=1, N;
    cin>>N;
    while (i<=N) {
        int j = i, k=2, l=1;
        while (l<=N-i)
        {
            cout<<" ";
            l++;
        }
        
        while (j>=1) {
            cout<<j;
            j--;
        }
        while (k <= i) {
            cout<<k;
            k++;
        }
        cout<<endl;
        i++;
    }
    
}