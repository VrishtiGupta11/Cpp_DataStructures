#include<iostream>
#include<climits>
using namespace std;

int main() {
    int testCases, testCasesCopy, output[50][50], N1, N2;
    cin>>testCases;
    testCasesCopy = testCases;
    while (testCases > 0)
    {
        int array1[100], array2[100], k=0;
        cin>>N1;
        for(int i=0; i<N1; i++){
            cin>>array1[i];
        }
        cin>>N2;
        for(int i=0; i<N2; i++){
            cin>>array2[i];
        }
        for(int i=0; i<N1; i++, k++){
            for(int j=0; j<N2; j++){
                if(array1[i] == array2[j]){
                    // output[testCasesCopy-testCases][k] = array2[j];
                    cout<<array1[i]<<" ";
                    array2[j] = INT_MIN;
                    break;
                }
            }
        }

        cout<<endl<<endl;
        testCases--;
    }

    // for(int i=0; i<testCasesCopy; i++){
    //     for(int j=0; j<N1;j++){
    //         cout<<output[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}