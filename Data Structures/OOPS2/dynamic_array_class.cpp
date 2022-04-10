#include <iostream>
using namespace std;

class DynamicArray{
    int *data;
    int nextIndex;
    int capacity;
    public:
    DynamicArray() {
        data = new int[5];
        capacity = 5;
        nextIndex = 0;
    }
    DynamicArray(DynamicArray const &d) {
        data = new int[d.capacity];
        for(int i=0; i<d.nextIndex; i++)
            data[i] = d.data[i];
        capacity = d.capacity;
        nextIndex = d.nextIndex;
    }
    void add(int element) {
        if(nextIndex == capacity) {
            int *newData = new int[2*capacity];
            for(int i=0; i<nextIndex; i++)
                newData[i] = data[i];
            delete [] data;
            data = newData;
        }
        data[nextIndex++] = element;
    }
    void add(int i, int element) {
        if(i < nextIndex) 
            data[i] = element;
        else if(i == nextIndex) 
            add(element);
        else
            return;
    }
    void print() {
        for(int i=0; i<nextIndex; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.print();
    DynamicArray d2 = d1;
    d1.add(30);
    d1.print();
    d2.print();
}