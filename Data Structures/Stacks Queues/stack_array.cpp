#include <iostream>
#include <climits>
using namespace std;

class Stack {
    int* data;
    int nextIndex;
    int capacity;
public:
    Stack() {
        capacity = 4;
        data = new int[capacity];
        nextIndex = 0;
    }

    // push -> to insert an element
    // here element is pushed dynamically i.e. when array gets filled a new array is created with double capacity.
    void push(int element) {
        if(nextIndex == capacity) {
            int* newData = new int[2*capacity];
            for(int i=0; i<capacity; i++) {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
        }
        data[nextIndex++] = element;
    }

    // pop -> to remove an element
    int pop() {
        if(nextIndex == 0) {
            cout << "Stack is empty";
            return INT_MIN; 
        }
        nextIndex--;
        return data[nextIndex];
    }

    // top -> to access the top element
    int top() {
        if(nextIndex == 0) {
            cout << "Stack is empty";
            return INT_MIN; 
        }
        return nextIndex - 1;
    }

    // size -> to check stack size
    int size() {
        return nextIndex;
    }

    // isEmpty -> to check whether stack is empty or not
    bool isEmpty() {
        return nextIndex == 0;
    }
};