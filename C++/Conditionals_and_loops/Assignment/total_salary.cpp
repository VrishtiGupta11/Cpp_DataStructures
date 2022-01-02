#include<iostream>
#include <cmath>
using namespace std;

int main(){
    int basic, allow;
    char grade;
    cin>>basic>>grade;
    float hra = (float)(20*basic)/100;
    float da = (float)(50*basic)/100;
    allow = grade == 'A' || grade == 'a' ? 1700 : grade == 'B' || grade == 'b' ? 1500 : 1300;
    float pf = (float)(11*basic)/100;
    float totalSalary = (float)basic + hra + da + allow - pf;
    cout<<round(totalSalary);
    return 0;
}