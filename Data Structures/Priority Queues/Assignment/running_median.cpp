#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

void runningMedian(int* arr, int N) {
    priority_queue<int, vector<int>, greater<int>> minpq;
    priority_queue<int> maxpq;
    for(int i=0; i<N; i++) {
        if(maxpq.empty() && minpq.empty()) {
            maxpq.push(arr[i]);
        }
        else if(arr[i] > maxpq.top()) 
            minpq.push(arr[i]);
        else if(arr[i] <= maxpq.top())
            maxpq.push(arr[i]);
        
        int minSize = minpq.size();
        int maxSize = maxpq.size();

        if(maxSize - minSize > 1) {
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        else if(minSize - maxSize > 1) {
            maxpq.push(minpq.top());
            minpq.pop();
        }

        if((minpq.size() + maxpq.size()) % 2 == 0)
            cout << (maxpq.top() + minpq.top())/2 << endl;
        else {
            if(minpq.size() > maxpq.size())
                cout << minpq.top() << endl;
            else
                cout << maxpq.top() << endl;
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
    runningMedian(arr, N);
}