#include<iostream>
using namespace std;

int SumTwoArrays(int arr1[], int N1, int arr2[], int N2, int arr[]){
    int N = (N1 > N2) ? N1 : N2;
    int i=N1-1, j=N2-1, k=N, carry=0, number;
    while (k >= 0) {
        if(i >= 0 && j >= 0)
            number = arr1[i] + arr2[j] + carry;
        else if(i >= 0)
            number = arr1[i] + carry;
        else if(j >= 0)
            number = arr2[j] + carry;
        else
            number = carry;
        arr[k] = number%10;
        carry = (number/10)%10;
        i--; j--; k--;
    }
    return (N+1);
}

int main() {
    int testCases;
    cin>>testCases;
    while (testCases > 0)
    {
        int N1, array1[100], N2, array2[100], array[100] = {0}, N;
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