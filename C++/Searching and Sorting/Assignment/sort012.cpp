#include<iostream>
using namespace std;

void Sort012(int arr[], int N) {
    int count0=0, count1 = 0, count2=0;
    for(int i=0; i<N; i++){
        if(arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else if (arr[i] == 2)
            count2++;
    }
    int i=0;
    for(; i<count0; i++)
        arr[i] = 0;
    for(; i<count0+count1; i++)
        arr[i] = 1;
    for(; i<count0+count1+count2; i++){
        arr[i] = 2;
    }
}

void SORT012(int arr[], int N){
    int next0=0, next2=N-1, i=0;
    while(i <= next2){
        if(arr[i] == 0){
            if(i == next0){
                i++;
                next0++;
                continue;
            }
            arr[i] = arr[next0];
            arr[next0++] = 0;
        }
        else if(arr[i] == 2){
            if(i == next2){
                i++;
                continue;
            }
            arr[i] = arr[next2];
            arr[next2--] = 2;
        }
        else{
            i++;
        }
    }
}

int main() {
    int testCases;
    cin>>testCases;
    while (testCases > 0)
    {
        int N, array[100];
        cin>>N;
        for(int i=0; i<N; i++){
            cin>>array[i];
        }
        SORT012(array, N);
        for(int i=0; i<N; i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
        testCases--;
    }
}