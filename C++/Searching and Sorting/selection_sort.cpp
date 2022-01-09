#include<iostream>
#include<climits>
using namespace std;

void SelectionSort(int array[], int N){
    int start=0;
    while (start < N)
    {
        int minInd = start;
        for(int i=start; i<N; i++){
            if(array[i] < array[minInd])
                minInd = i;
        }
        int temp = array[start];
        array[start] = array[minInd];
        array[minInd] = temp;
        start++;
    }
}

int main() {
    int array[100], N;
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>array[i];

    SelectionSort(array, N);
    
    for(int i=0; i<N; i++)
        cout<<array[i]<<" ";
}