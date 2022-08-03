#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class MaxPriorityQueue {
    vector<int> pq;
public: 
    int getSize() {
        return pq.size();
    }

    bool isEmpty() {
        return pq.size() == 0;
    }

    int getMax() {
        if(pq.size() == 0) 
            return INT_MIN;
        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);
        int childIndex = pq.size() - 1;

        while(childIndex > 0) {
            int parentIndex = (childIndex - 1)/2;

            if(pq[childIndex] > pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
                break;
            childIndex = parentIndex;
        }
    }

    int removeMax() {
        if(pq.size() == 0) 
            return INT_MIN;
        int toRemove = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();

        int PI = 0;  // Parent Index
        int LCI = 2*PI + 1;  // Left Child Index
        int RCI = 2*PI + 2;  // Right Child Index
        
        while(LCI < pq.size()) {
            int minIndex = PI;
            if(pq[LCI] > pq[minIndex])
                minIndex = LCI;
            if(pq[RCI] > pq[minIndex])
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