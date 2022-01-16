#include<iostream>
using namespace std;

int main() {
    int m, n, arr[100][100], output[100] = {0};
    cin>>m>>n;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>arr[i][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            output[i] += arr[j][i];
    for(int i=0; i<n; i++)
        cout<<output[i]<<" ";
}