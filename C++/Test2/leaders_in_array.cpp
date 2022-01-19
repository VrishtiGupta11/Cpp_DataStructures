#include<iostream>
using namespace std;

void LeadersInArray(int arr[], int N){
    int leaders[100], j=1;
    leaders[0] = arr[N-1];
    for(int i=N-2; i>=0; i--){
        if(arr[i] >= leaders[j-1])
            leaders[j++] = arr[i];
    }
    for(int i=j-1; i>=0; i--){
        cout<<leaders[i]<<" ";
    }
}

int main() {
    int arr[100], N;
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>arr[i];
    LeadersInArray(arr, N);
}