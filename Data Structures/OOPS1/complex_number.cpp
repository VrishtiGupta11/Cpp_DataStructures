#include <iostream>
using namespace std;

class ComplexNumber
{
    private:
        int real, imaginary;
    public:
        ComplexNumber(int real, int imaginary) {
            this->real = real;
            this->imaginary = imaginary;
        }
        void plus(ComplexNumber c2) {
            this->real += c2.real;
            this->imaginary += c2.imaginary;
        }
        void multiply(ComplexNumber c2) {
            int real = (this->real * c2.real) - (this->imaginary * c2.imaginary);
            int img = this->real*c2.imaginary + this->imaginary*c2.real;
            this->real = real;
            this->imaginary = img;
        }
        void print() {
            cout << this->real << " + " << "i" << this->imaginary << endl;
        }
};
