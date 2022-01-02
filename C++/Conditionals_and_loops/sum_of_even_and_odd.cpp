#include<iostream>
using namespace std;

int main(){
    int N, evenSum=0, oddSum=0, rem;
    cin>> N;
    while (N>0)
    {
        rem = N%10;
        if(rem % 2 == 0){
            evenSum += rem;
        }
        else{
            oddSum += rem;
        }
        N /= 10;
    }
    cout<<evenSum<<"\t"<<oddSum<<endl;
}