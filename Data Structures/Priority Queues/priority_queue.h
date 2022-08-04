#include <iostream>
#include <vector>
using namespace std;

// Priority queues are implemented using Min Heap or Max Heap
// Heap => Complete Binary Tree + Heap Ordering property (Max -> Min/ Min -> Max)
// Here we are assuming that element and its priority are same

class PriorityQueue {
    vector<int> pq;
public:
    void printPQ() {
        for(int i=0; i<pq.size(); i++)
            cout << pq[i] << " ";
    }

    // Get Size
    int getSize() {
        return pq.size();
    }

    // Is Empty
    bool isEmpty() {
        return pq.size() == 0;
    }

    // Get Min
    int getMin() {
        if(pq.size() == 0) 
            return 0;
        return pq.at(0);
    }

    // Insert
    void insert(int element) {
        pq.push_back(element);
        int childIndex = pq.size() - 1;

        while(childIndex > 0) {
            int parentIndex = (childIndex - 1)/2;

            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
                break;
            childIndex = parentIndex;
        }
    }

    // Remove
    int removeMin() {
        if(pq.size() == 0) 
            return 0;
        int toRemove = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();

        int PI = 0;
        int LCI = 2*PI + 1;
        int RCI = 2*PI + 2;
        
        while(LCI < pq.size()) {
            int minIndex = PI;
            if(pq[LCI] < pq[minIndex])
                minIndex = LCI;
            if(RCI < pq.size() && pq[RCI] < pq[minIndex])
                minIndex = RCI;
            if(minIndex == PI)
                break;
            int temp = pq[minIndex];
            pq[minIndex] = pq[PI];
            pq[PI] = temp;

            PI = minIndex;
            LCI = 2*PI + 1;
            RCI = 2*PI + 2;
        }

        return toRemove;
    }

};