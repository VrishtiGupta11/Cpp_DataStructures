#include <iostream>
#include <queue>
using namespace std;

void kSortedArray(int* arr, int N, int k) {
    priority_queue<int> pq;
    for(int i=0; i<k; i++) {
        pq.push(arr[i]);
    }
    int j=0;
    for(int i=k; i<N; i++) {
        arr[j++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while(!pq.empty()) {
        arr[j++] = pq.top();
        pq.pop();
    }
}

int main() {
    int N, k;
    cin >> N;
    int* arr = new int[N];
    for(int i=0; i<N; i++)
        cin >> arr[i];
    cin >> k;
    kSortedArray(arr, N, k);
    for(int i=0; i<N; i++)
        cout << arr[i] << " ";
}