#include <iostream>
#include <queue>
using namespace std;

int buyTheTicket(int* arr, int N, int index) {
    queue<int> q;
    priority_queue<int> pq;
    for(int i=0; i<N; i++) {
        q.push(i);
        pq.push(arr[i]);
    }
    int time = 0;
    while(!q.empty()) {
        if(arr[q.front()] == pq.top()) {
            time++;
            if(q.front() == index)
                break;
            q.pop();
            pq.pop();
        }
        else {
            q.push(q.front());
            q.pop();
        }
    }
    return time;
}

int main() {
    int N, index;
    cin >> N;
    int* arr = new int[N];
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    cin >> index;
    cout << buyTheTicket(arr, N, index) << endl;
}