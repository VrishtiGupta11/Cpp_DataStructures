#include <iostream>
using namespace std;

class Student {
    static int totalStudents;
    int rollNo;
    int age;
public:
    Student() {
        totalStudents++;
    }
    // int getTotalStudents() {       // Non static can access all the members be it static or non static.
    //     return totalStudents;
    // }
    int static getTotalStudents() {    // Static functions can only access static members.
        return totalStudents;
    }
};
int Student :: totalStudents = 0;    // Initialization

int main() {
    Student s1, s2;
    cout << Student :: getTotalStudents() << endl;
    cout << s1.getTotalStudents() << endl;     // Correct answer but Logically incorrect as static members belongs to class not to objects.
}