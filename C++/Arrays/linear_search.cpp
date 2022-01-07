#include<iostream>
using namespace std;

int main() {
    int testCases, testCasesCopy, N, toSearch, arr[100], i, output[100];
    cin>>testCases;
    testCasesCopy = testCases;

    while (testCases > 0)
    {
        cin>>N;
        for(int i=0; i<N; i++) {
            cin>>arr[i];
        }
        cin>>toSearch;
        for(i=0; i<N; i++) {
            if(toSearch == arr[i]) {
                output[testCases-1] = i;
                break;
            }
        }
        if(i == N) {
            output[testCases-1] = -1;
        }
        testCases--;
    }
    for(int j = testCasesCopy-1; j>=0; j--){
        cout<<output[j]<<endl;
    }
   
}