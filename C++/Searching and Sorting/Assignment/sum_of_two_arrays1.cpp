#include<iostream>
#include<cmath>
using namespace std;

int NumberToArray(int number, int arr[]) {
    int N=0;
    while (number > 0) {
        arr[N] = number%10;
        number /= 10;
        N++;
    }
    return N;
}

void ReverseArray(int arr[], int start, int end){
    for(int i=start, j=end; i<j; i++, j--){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int SumTwoArrays(int arr1[], int N1, int arr2[], int N2, int arr[]) {
    int i=N1-1, j=N2-1, sum=0, N;
    while (i>=0 && j>=0) {
        sum += (arr1[i] + arr2[j])*pow(10, N1-i-1);
        i--;
        j--;
    }
    while (i >= 0) {
        sum += arr1[i]*pow(10, N1-i-1);
        i--;
    }
    while (j >= 0) {
        sum += arr1[j]*pow(10, N2-j-1);
        j--;
    }
    cout<<sum<<endl;
    N = NumberToArray(sum, arr);
    ReverseArray(arr, 0, N-1);
    return N;
}

int main() {
    int testCases;
    cin>>testCases;
    while (testCases > 0)
    {
        int N1, array1[100], N2, array2[100], array[100], N;
        cin>>N1;
        for(int i=0; i<N1; i++){
            cin>>array1[i];
        }
        cin>>N2;
        for(int i=0; i<N2; i++){
            cin>>array2[i];
        }
        N = SumTwoArrays(array1, N1, array2, N2, array);
        for(int i=0; i<N; i++){
            cout<<array[i]<<" ";
        }
        cout<<endl<<endl;
        testCases--;
    }
}