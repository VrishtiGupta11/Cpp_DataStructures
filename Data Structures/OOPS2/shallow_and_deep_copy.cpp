#include <iostream>
#include <string.h>
using namespace std;

class Student
{
private:
    int age;
    char* name;
public:
    Student(int age, char* name) {
        this->age = age;
        // Shallow copy
        // this->name = name;
        
        // Deep Copy
        this->name = new char[strlen(name)];
        strcpy(this->name, name);
    }
    void display() {
        cout << this->age << endl;
        cout << this->name << endl;
    }
};

int main() {
    char name[] = "abcd";
    Student s1(12, name);
    name[3] = 'e';
    Student s2(15, name);
    s1.display();
    s2.display();
}