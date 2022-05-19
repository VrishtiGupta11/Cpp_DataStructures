#include <iostream>
using namespace std;

template <typename T>
class Queue {
    T* data;
    int nextIndex, firstIndex, capacity, N;
public: 
    Queue() {
        capacity = 4;
        data = new T[capacity];
        nextIndex = 0;
        firstIndex = -1;
        N = 0;
    }

    void enqueue(T element) {
        if(firstIndex == -1) {
            firstIndex = 0;
        }
        if(N == capacity) {
            T* newData = new T[2*capacity];
            int i=firstIndex, j=0;
            while((firstIndex+i)%capacity != nextIndex) {
                newData[j++] = data[i++];
            }
            delete data;
            data = newData;
            nextIndex = capacity;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1)%capacity;
        N++;
    }

    T dequeue() {
        if(isEmpty()) {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        T temp = data[firstIndex];
        firstIndex = (firstIndex + 1)%capacity;
        N--;
        return temp;
    }

    T front() {
        if(isEmpty()) {
            cout << "Queue is empty!" << endl;
            return 0;
        }
        return data[firstIndex];
    }

    int size() {
        return N;
    }

    bool isEmpty() {
        return N == 0;
    }
};