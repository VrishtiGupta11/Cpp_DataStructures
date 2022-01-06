#include<iostream>
using namespace std;

int fahToCel(float f){
    return ((5*(f-32))/9);
}

int main() {
    float start, end, stepSize;
    cin>>start>>end>>stepSize;
    while (start<=end)
    {
        cout<<start<<" "<<fahToCel(start)<<endl;
        start += stepSize;
    }
    return 0;
}