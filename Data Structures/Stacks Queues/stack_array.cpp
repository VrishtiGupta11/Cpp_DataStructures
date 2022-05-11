#include <iostream>
#include <climits>
using namespace std;

template <typename T>
class Stack {
    T* data;
    int nextIndex;
    int capacity;
public:
    Stack() {
        capacity = 4;
        data = new T[capacity];
        nextIndex = 0;
    }

    // push -> to insert an element
    // here element is pushed dynamically i.e. when array gets filled a new array is created with double capacity.
    void push(T element) {
        if(nextIndex == capacity) {
            T* newData = new T[2*capacity];
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
    T pop() {
        if(nextIndex == 0) {
            cout << "Stack is empty";
            return 0; 
        }
        nextIndex--;
        return data[nextIndex];
    }

    // top -> to access the top element
    T top() {
        if(nextIndex == 0) {
            cout << "Stack is empty";
            return 0; 
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