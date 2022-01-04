#include<iostream>
using namespace std;

int main() {
    int number, choice, sum=0, product=1;
    cin>>number;
    cout<<"Enter 1 to print the sum\nEnter 2 to print the product\n";
    cin>>choice;
    if(choice==1){
        for(int i=1; i<=number; i++){
            sum += i;
        }
        cout<<sum<<endl;
    }
    else if (choice == 2){
        for(int i=1; i<=number; i++){
            product *= i;
        }
        cout<<product<<endl;
    }
    else{
        cout<<"-1\n";
    }
    return 0;
}