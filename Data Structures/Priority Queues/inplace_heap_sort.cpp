#include <iostream>
using namespace std;

// Overall Time complexity => O(nlogn)
// Overall Space complexity => O(1);

void buildHeap(int* arr, int N) {
    for(int i=1; i<N; i++) {
        int childIndex = i;
        while(childIndex > 0) {
            int parentIndex = (childIndex-1)/2;
            if(arr[childIndex] < arr[parentIndex]) {
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
    }
    // for(int i=0; i<N; i++) 
    //     cout << arr[i] << " ";
}

void removeMin(int* arr, int N) {
    int size = N;
    while(size > 1) {
        int toRemove = arr[0];
        arr[0] = arr[size-1];
        arr[size-1] = toRemove;

        size--;
        
        int parentindex = 0;
        int leftChildIndex = 2*parentindex + 1;
        int rightChildIndex = 2*parentindex + 2;
        
        while(leftChildIndex < size) {
            int minIndex = parentindex;
            if(arr[leftChildIndex] < arr[minIndex])
                minIndex = leftChildIndex;
            if(rightChildIndex < size && arr[rightChildIndex] < arr[minIndex])
                minIndex = rightChildIndex;
            if(minIndex == parentindex)
                break;
            int temp = arr[minIndex];
            arr[minIndex] = arr[parentindex];
            arr[parentindex] = temp;

            parentindex = minIndex;
            leftChildIndex = 2*parentindex + 1;
            rightChildIndex = 2*parentindex + 2;
        }
    }
}

int main() {
    int N;
    cin >> N;
    int* arr = new int[N];
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    buildHeap(arr, N);
    removeMin(arr, N);
    for(int i=0; i<N; i++) {
        cout << arr[i] << " ";
    }
}