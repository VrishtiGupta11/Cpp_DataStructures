#include<iostream>
using namespace std;

int main() {
    int testCases, testCasesCopy, output[100];
    cin>>testCases;
    testCasesCopy = testCases;
    while (testCases > 0)
    {
        int N, array[100], sum, count=0;
        cin>>N;
        for(int i=0; i<N; i++){
            cin>>array[i];
        }
        cin>>sum;
        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                if(array[i] + array[j] == sum){
                    count++;
                }
            }
        }
        output[testCasesCopy-testCases] = count;

        cout<<endl;
        testCases--;
    }
    for(int i=0; i<testCasesCopy; i++){
        cout<<output[i]<<endl;
    }
    
}