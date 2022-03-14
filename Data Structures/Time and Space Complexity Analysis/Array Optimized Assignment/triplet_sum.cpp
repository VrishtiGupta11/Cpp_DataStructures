#include <iostream>
using namespace std;

void Merge(int arr[], int l, int mid, int h) {
    int arr1[100], i = l, j = mid+1, k=0;
    while(i <= mid && j <= h) {
        if(arr[i] < arr[j])
            arr1[k++] = arr[i++];
        else 
            arr1[k++] = arr[j++];
    }
    while(i <= mid) {
        arr1[k++] = arr[i++];
    }
    while(j <= h) {
        arr1[k++] = arr[j++];
    }
    for(int i=l; i <= h; i++) {
        arr[i] = arr1[i-l];
    }
}

void MergeSort(int arr[], int l, int h) {
    if(l >= h)
        return;
    int mid = (l + h)/2;
    MergeSort(arr, l, mid);
    MergeSort(arr, mid+1, h);
    Merge(arr, l, mid, h);
}

int TripletSum(int arr[], int N, int sum) {
    MergeSort(arr, 0, N-1);
    int count = 0, k=0;
    while(k < N-1) {
        int i=k+1, j=N-1;
        while(i < j) {
            if(arr[i]+arr[j]+arr[k] < sum)
                i++;
            else if(arr[i]+arr[j]+arr[k] > sum)
                j--;
            else {
                if((arr[i] == arr[j]) && i<j) {
                    count += (j-i)*(j-i+1)/2;
                    break;
                }
                if((arr[i] != arr[i+1]) && (arr[j] != arr[j-1])) {
                    i++;
                    j--;
                    count++;
                }
                else {
                    int counti=1, countj=1;
                    while(arr[i] == arr[i+1] && i<j) {
                        counti++;
                        i++;
                    }
                    while(arr[j] == arr[j-1] && i<j) {
                        countj++;
                        j--;
                    }
                    i++;
                    j--;
                    count += counti*countj;
                }
                
            }
        }
        k++;
    }
    return count;
}

int main() {
    int N, sum;
    cin >> N;
    int* arr = new int[N];
    for(int i=0; i<N; i++)
        cin >> arr[i];
    cin >> sum;
    cout << TripletSum(arr, N, sum);
}