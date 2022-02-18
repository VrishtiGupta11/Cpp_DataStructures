// #include <sys/timeb.h>
// #include <sys/utime.h>
#include <iostream>
#include <time.h>
using namespace std;

long getTimeInNanoSeconds() {
    struct timespec start;
    if (timespec_get(&start, TIME_UTC) != TIME_UTC) {
        fputs("timespec_get failed!", stderr);
    }
    return start.tv_nsec*1000000000 + start.tv_nsec;
}

void Merge(int arr1[], int N1, int N2) {
    int arr[1000], i=0, j=N1, k=0;
    while (i < N1 && j < N2) {
        if(arr1[i] < arr1[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr1[j++];
    }
    while (i < N1) {
        arr[k++] = arr1[i++];
    }
    while (j < N2) {
        arr[k++] = arr1[j++];
    }
    for(int i=0; i<k; i++)
        arr1[i] = arr[i];
}

void MergeSort(int arr[], int l, int h) {
    if(l >= h) 
        return;
    int mid = (l+h)/2;
    MergeSort(arr, l, mid);
    MergeSort(arr, mid+1, h);
    Merge(arr, mid+1, h+1);
}

int main() {
    for(int n=10; n <= 1000000; n*= 10) {
        int *arr = new int[n];
        long starttime, endtime;
        for(int i=0; i<n; i++) {
            arr[i] = n-i;
        }
        starttime = getTimeInNanoSeconds();
        MergeSort(arr, 0, n-1);
        endtime = getTimeInNanoSeconds();
        cout << "Merge Sort n = " << n << " time = " << endtime-starttime << endl;
    }
}