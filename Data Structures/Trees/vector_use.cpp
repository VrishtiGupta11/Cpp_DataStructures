#include <iostream>
#include <vector>
using namespace std;

// Vector is an inbuilt dynamic array class implemented using Templates.

int main() {
    vector<int> v;
    
    cout << "Cap: " << v.capacity() << endl;
    cout << "Size: " << v.size() << endl; 
    
    for(int i=0; i<50; i++) {
        v.push_back(i);
        cout << "Cap: " << v.capacity() << endl;     // capacity of internal array. It gets changed as the size gets doubled whenever exceeds the capacity. 
        cout << "Size: " << v.size() << endl;       // Size of number of elements stored in the array.
    }

    // Always insert using push_back function.
    // To get an element or to update an element '[]' can be used.
    for(int i=0; i<50; i++) 
        cout << v[i] << " ";
    
    cout << endl;

    // To change an element
    v[3] = 1234;
    
    // To delete the last element
    v.pop_back();

    // Alternatively we can all access an element using at().
    for(int i=0; i<v.size(); i++) 
        cout << v.at(i) << " ";
    
    cout << endl;
    cout << "Size: " << v.size() << endl;
}