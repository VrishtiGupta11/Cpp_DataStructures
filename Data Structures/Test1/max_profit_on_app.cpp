#include <iostream>
using namespace std;

int MaximumProfit(int budget[], int N) {
    int sum = 0, count = 0, maxAvg = budget[0];
    float avg;
    for(int i=0; i<N; i++) {
        sum += budget[i];
        if(budget[i] > maxAvg)
            maxAvg = budget[i];
    }
    
    avg = (float)sum/N;
    
    // MaxAvg is getting value just greater than avg
    for(int i=0; i<N; i++) {
        if(budget[i] > avg && budget[i] < maxAvg)
            maxAvg = budget[i];
    }
    for(int i=0; i<N; i++) {
        if(budget[i] >= maxAvg) 
            count++;
    }
    return count*maxAvg;
}

int main() {
    int N;
    cin >> N;
    int* budget = new int[N];
    for(int i=0; i<N; i++)
        cin >> budget[i];
    cout << MaximumProfit(budget, N);
}