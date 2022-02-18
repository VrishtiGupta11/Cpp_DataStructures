#include <iostream>
using namespace std;

// Approach 1 : Compare every number with each other to count
// Approach 2 : Sort the elements and then find the duplicate

// Approach 3 : time complexity -> O(n)
//              space complexity -> O(n)
int FindDuplicate1(int arr[], int size) {
    int* count = new int[size] {0};
    for(int i=0; i<size; i++)
        count[arr[i]]++;
    for(int i=0; i<size-1; i++) {
        if(count[i] == 2)
            return i;
    }
}

// Approach 4 : time complexity -> O(n)
//              space complexity -> O(1)
int FindDuplicate2(int arr[], int N) {
    int sum = 0;
    for(int i=0; i<N; i++)
        sum += arr[i];
    return sum - ((N-1)*(N-2)/2);
}

int main() {
    int testCases, testCasesCopy, output[100];
    cin >> testCases;
    testCasesCopy = testCases;
    while (testCases > 0) {
        int N;
        cin >> N;
        int* arr = new int[N];
        for(int i=0; i<N; i++) 
            cin>>arr[i];

        // output[testCasesCopy-testCases] = FindDuplicate1(arr, N);
        output[testCasesCopy-testCases] = FindDuplicate2(arr, N);
        
        cout<<endl;
        testCases--;
    }
    for(int i=0; i<testCasesCopy; i++)
        cout<<output[i]<<endl;
}