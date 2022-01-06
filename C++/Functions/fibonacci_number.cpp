#include<iostream>
using namespace std;

int fibonacci(int N){
    if(N == 0 || N == 1){
        return N;
    }
    return fibonacci(N-1)+fibonacci(N-2);
}

bool isInFibonacci(int N){
    int i = 0;
    while(fibonacci(i) <= N){
        if(fibonacci(i) == N){
            return true;
        }
        i++;
    }
    return false;
}

int main() {
    int N;
    cin>>N;
    if(isInFibonacci(N)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}