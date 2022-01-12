#include<iostream>
#include<climits>
using namespace std;

// This approach is fine if we have case like 1 5 8 3 8 and second Largest to be considered is 8.
int SecondLargest1(int arr[], int N) {
    for(int i=0; i<2; i++) {
        for(int j=0; j<N-i; j++) {
            if(arr[j+1] < arr[j]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr[N-2];
}

// Second largest in just 1 scan and here from 1 5 8 3 8, second largest will be 5
int SecondLargest2(int arr[], int N) {
    int largest = INT_MIN, secondLargest = INT_MIN;
    for(int i=0; i<N; i++) {
        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
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
        output[testCasesCopy - testCases] = SecondLargest2(array, N);
        
        cout<<endl;
        testCases--;
    }
    for(int i=0; i<testCasesCopy; i++){
        cout<<output[i]<<endl;
    }
}