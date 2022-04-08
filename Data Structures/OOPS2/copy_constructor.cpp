#include <iostream>
#include <string.h>
using namespace std;

class Student {
public:
    int age;
    char* name;
public:
    Student(int age, char* name) {
        this->age = age;
        // Deep Copy
        this->name = new char[strlen(name)];
        strcpy(this->name, name);
    }

    Student(Student const &s) {     // Reference is added in order to prevent infinite loop in calling copy constructor. Const is added in order to prevent s2 from changing the value of s1 as they are pointing on the same object.
        this->age = s.age;
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }

    void display() {
        cout << this->age << endl;
        cout << this->name << endl;
    }
};

int main() {
    char name[] = "abcd";
    Student s1(12, name);
    s1.display();
    Student s2(s1);
    s2.name[3] = 'e';
    s1.display();
    s2.display();
}