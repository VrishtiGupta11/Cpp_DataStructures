#include <iostream>
using namespace std;

class Student {
private:
    int age;
    int const rollNumber;
    // int& x = age;
    int& x;
public:
    Student(int a, int r) : age(a), rollNumber(r), x(this->age) {}   // Initialization List
    void display() {
        cout << "age: " << age << endl;
        cout << "rollNumber: " << rollNumber << endl;
        cout << "x: " << x << endl;
    }
};

int main() {
    Student s1(20, 2);
    Student s2(25, 4);
    s1.display();
    s2.display();
}