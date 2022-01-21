#include<iostream>
using namespace std;

// Approach 1 - In this approach, firstly all even numbers are placed in the array and then all odd numbers.
/*
int main() {
    int testCases, testCasesCopy, N, arr[100], odd, even, *output[100], narray[100];
    cin>>testCases;
    testCasesCopy = testCases;
    while (testCases > 0)
    {
        odd = 1;
        // cout<<"Testcase:"<<testCases<<endl;
        cin>>N;
        if(N%2 == 0) {
            int i=0;
            even = N;
            for(; i<N/2; i++) {
                arr[i] = odd;
                odd += 2;
            }
            for(; i<N; i++) {
                arr[i] = even;
                even -= 2;
            }
        }
        else{
            int j=0;
            even = N-1;
            for(j=0; j<N/2+1; j++) {
                arr[j] = odd;
                odd += 2;
            }
            for(; j<N; j++) {
                arr[j] = even;
                even -= 2;
            }
        }

        for(int i=0; i<N; i++){
            cout<<arr[i]<<" ";
        }
        
        cout<<endl;

        // narray[(testCasesCopy - testCases)] = N;
        // output[(testCasesCopy - testCases)] = arr;
        
        testCases--;
    }

    // for(int i=0; i<testCasesCopy; i++){
    //     for(int j=0; j<narray[i]; j++){
    //         cout<<output[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
}
*/

// Approach 2 - taking 2 pointers 1st one starting from starting index and 2nd one starting from last index and putting the value into array simultaneously via both the indexes.

int main(){
    int testCases;
    cin>>testCases;
    while (testCases > 0)
    {
        int N, arr[100], count = 1;
        cin>>N;
        for(int i=0, j=N-1; i<N/2 || j>=N/2; i++, j--){
            if(i==j){
                arr[i] = count;
                break;
            }
            arr[i] = count;
            count++;
            arr[j] = count;
            count++;
        }
        /*
        if(N%2 != 0){
            for(int i=0, j=N-1; i<N/2 || j>=N/2; i++, j--){
                if(i==j){
                    arr[i] = count;
                    break;
                }
                arr[i] = count;
                count++;
                arr[j] = count;
                count++;
                // cout<<i<<" "<<j<<endl;
            }
        }
        else{
            for(int i=0, j=N-1; i<N/2 && j>=N/2; i++, j--){
                arr[i] = count;
                count++;
                arr[j] = count;
                count++;
            }
        }
        */
        for(int i=0; i<N; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

        testCases--;
    }
    
}