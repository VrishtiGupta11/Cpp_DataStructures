#include<iostream>
using namespace std;

int main() {
    char c;
    c = cin.get();
    int ccount = 0, dcount = 0, scount = 0;
    while (c != '$')
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            ccount++;
        if (c == '\n' || c == '\t' || c == ' ')
            scount++;
        if (c >= '0' && c <= '9')
            dcount++;
        c = cin.get();
    }
    cout<<ccount<<" "<<dcount<<" "<<scount<<endl;
}