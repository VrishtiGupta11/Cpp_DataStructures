#include<iostream>
#include<climits>
using namespace std;

int main() {
    int N, element, l = INT_MIN, sl = INT_MIN;
    cin>>N;
    while(N>0){
        cin>>element;
        if(element > l){
            sl = l;
            l = element;
        }
        else if(element > sl && element != l){
            sl = element;
        }
        N--;
    }
    cout<<l<<endl<<sl;
}