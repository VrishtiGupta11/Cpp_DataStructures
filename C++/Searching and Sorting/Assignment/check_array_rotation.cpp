#include<iostream>
using namespace std;

int RotatedArrayIndex(int arr[], int N){
    int i=1;
    for(; i<N; i++){
        if(arr[i] < arr[i-1])
            return i;
    }
    if(i == N){
        return 0;
    }
}

int main() {
    int testCases, testCasesCopy, output[100];
    cin>>testCases;
    testCasesCopy = testCases;
    while (testCases > 0)
    {
        int N, array[100];
        cin>>N;
        for(int i=0; i<N; i++){
            cin>>array[i];
        }
        output[testCasesCopy - testCases] = RotatedArrayIndex(array, N);
        
        cout<<endl;
        testCases--;
    }
    for(int i=0; i<testCasesCopy; i++){
        cout<<output[i]<<endl;
    }
}