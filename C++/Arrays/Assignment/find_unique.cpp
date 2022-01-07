#include<iostream>
using namespace std;

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
        for(int i=0; i<N; i++){
            int count = 0;
            for(int j=0; j<N; j++){
                // if(i == j){
                //     continue;
                // }
                if(array[i] == array[j]){
                    count++;
                }
            }
            if(count == 1){
                // cout<<array[i];
                output[testCasesCopy-testCases] = array[i];
                break;
            }
        }
        cout<<endl;
        testCases--;
    }

    for(int i=0; i<testCasesCopy; i++){
        cout<<output[i]<<endl;
    }
    
}