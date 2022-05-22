#include <iostream>
using namespace std;

template <typename T>
class Dequeue{
    T* data;
    int size;
    int first;
    int rear;
    int capacity;
public:
    Dequeue() {
        capacity = 4;
        data = new T[capacity];
        size = 0;
        first = 0;
        rear = 0;
    }

    // insertFront
    void insertFront(T element) {
        if(size == capacity) {
            cout << "Double ended Queue is full!" << endl;
            return;
        }
        data[first] = element;
        if(first == 0) {
            first = capacity-1;
            rear++;
        }
        else 
            first--;
        // rear = (rear+1)%capacity;
        size++;
    }

    // insertRear
    void insertRear(T element) {
        if(size == capacity) {
            cout << "Double ended Queue is full!" << endl;
            return;
        }
        data[rear] = element;
        if(rear == 0)
            first = capacity - 1;
        rear = (rear+1)%capacity;  
        size++;
    }

    // deleteFront
    T deleteFront() {
        if(size == 0) {
            cout << "Double ended Queue is empty!" << endl;
            return -1;
        }
        first = (first+1)%capacity;
        size--;
        return data[first];
    }

    // deleteRear
    T deleteRear() {
        if(size == 0) {
            cout << "Double ended Queue is empty!" << endl;
            return -1;
        }
        if(rear == 0)
            rear = capacity - 1;
        else 
            rear = (rear-1)%capacity;
        size--;
        return data[rear];
    }

    // getFront
    T getFront() {
        if(size == 0) {
            cout << "Double ended Queue is empty!" << endl;
            return -1;
        }
        return data[(first+1)%capacity];
        
    }

    // getRear
    T getRear() {
        if(size == 0) {
            cout << "Double ended Queue is empty!" << endl;
            return -1;
        }
        if(rear == 0)
            return data[capacity - 1];
        else 
            return data[(rear-1)%capacity];
    }

    int sizeN() {
        return size;
    }
};
 