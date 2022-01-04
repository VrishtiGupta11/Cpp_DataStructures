#include<iostream>
using namespace std;

int main() {
    int N, previous, current, i=1;
    bool isDec = true;
    cin>>N;
    cin>>previous;
    for(; i<N; i++){
        cin>>current;
        if(previous == current){
            cout<<"false\n";
            break;
        }
        else if (current < previous)
        {
            if(!isDec){
                cout<<"false\n";
                break;
            }
        }
        else if(current > previous){
            if(isDec){
                isDec = false;
            }
        }
        previous = current;
    }
    if(i == N)
        cout<<"true\n";
}