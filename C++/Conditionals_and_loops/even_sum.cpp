#include<iostream>
using namespace std;

int main(){
    int N;
    cout<<"Enter N: ";
    cin>>N;
    int count = 0, sum = 0;
    while(count <= N){
        sum += count;
        count += 2;
    }
    cout<<"Sum of even numbers from 0 to "<<N<<" is "<<sum<<endl;
    return 0;
}