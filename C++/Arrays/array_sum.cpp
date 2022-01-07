#include<iostream>
using namespace std;

int main() {
    int N, arr[100], sum = 0;
    cin>>N;
    for (int i=0; i<N; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    cout<<sum<<endl;
    return 0;
}