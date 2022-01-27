#include<iostream>
using namespace std;

int main() {
    const int i = 10;
    // i++; // Not allowed

    int j = 12;
    const int &k = j;
    // k++; // Not allowed
    // j++; // allowed
    
    int const j2 = 12;
    int const &k2 = j2;
    // j2++; // Not Allowed
    // k2++; // Not Allowed

    int const j3 = 12;
    // int &k3 = j3; // Not allowed

    int const i1 = 10;
    // int *p = &i; // Not allowed
    int const *p = &i1; // allowed

    int i2 = 12;
    int const *p2 = &i2;   // p2 is a pointer pointing to a contant integer.
    // i2++; // allowed
    // (*p2)++ // Not allowed
    // p2++; // allowed

    int *const p3 = &i2;  // p3 is a constant pointer pointing to an integer.
    // p3++; // Not allowed
    // *(p3)++; // Not allowed

    int const * const p4 = &i2;
    // p4++; // Not allowed
    // (*p4)++; // Not allowed
}