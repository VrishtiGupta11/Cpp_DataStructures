#include<iostream>
using namespace std;

// int main() {
//     int N;
//     cin>>N;
//     // for(int i=0, j=N-1; i<N/2 || j>=N/2; i++, j--){
//     //     cout<<i<<" "<<j<<endl;
//     // }
//     for(int i=0, j=N-1; i<N/2 && j>=N/2; i++, j--){
//         cout<<i<<" "<<j<<endl;
//     }
// }

int main() {
    int N=5;
    for(int i=0, j=N-1; i<N/2 && j>=N/2; i++, j--){
        cout<<i<<" "<<j<<endl;
    }
}