#include <iostream>
using namespace std;
class Fraction {
    private:
        int numerator;
        int denominator;
    public:
        Fraction(int numerator, int denominator) {
            this->numerator = numerator;
            this->denominator = denominator;
        }
        void print() {
            cout << numerator << "/" << denominator << endl;
        }
        void addFractions(Fraction f1) {
            int num = (f1.numerator*this->denominator) + (this->numerator*f1.denominator);
            int den = f1.denominator*this->denominator;
            this->numerator = num;
            this->denominator = den;
            // this->simplify();
            simplify();
        }
        void simplify() {
            int minNum = this->numerator < this->denominator ? this->numerator : this->denominator;
            int gcd = 1;
            for(int i=1; i<=minNum; i++) {
                if(this->numerator % i == 0 && this->denominator % i == 0)
                    gcd = i;
            }
            this->numerator = this->numerator/gcd;
            this->denominator = this->denominator/gcd;
        }
        Fraction operator+(Fraction const &f2) const {
            int num = (f2.numerator*this->denominator) + (this->numerator*f2.denominator);
            int den = f2.denominator*this->denominator; 
            Fraction fNew(num, den);
            fNew.simplify();
            return fNew;
        }
        Fraction operator*(Fraction const &f2) const {   // Since in this function we are not changing any value using this so we can make this function as const.
            int num = this->numerator * f2.numerator;
            int den = this->denominator * f2.denominator;
            Fraction fNew(num, den);
            fNew.simplify();
            return fNew;
        }
        bool operator==(Fraction const &f2) const {
            return this->numerator == f2.numerator && this->denominator == f2.denominator;
        }

        // Overloading ++ operator (Pre-increment)
        Fraction& operator++() {          // return type is Fraction reference in order to avoid copy i.e. work should not be done on buffer.
            this->numerator += this->denominator;
            simplify();
            return *this;
        }

        // Overloading ++ operator (Post-increment)
        Fraction operator++(int) {       // int is specified to tell that it is post increment operator.
            Fraction fNew(this->numerator, this->denominator);
            this->numerator += this->denominator;
            simplify();
            fNew.simplify();
            return fNew;
        }

        // Overloading += operator (Post-increment)
        Fraction& operator+=(Fraction const &f2) {
            numerator = (f2.numerator*this->denominator) + (this->numerator*f2.denominator);
            denominator = f2.denominator*this->denominator;
            simplify();
            return *this;
        }
};

int main() {
    Fraction f1(10, 3);
    Fraction f2(5, 2);
    Fraction f3 = f1 + f2;
    Fraction f4 = f1 * f2;
    cout << "Fraction 1" << endl;
    f1.print();
    cout << "Fraction 2" << endl;
    f2.print();
    cout << "f3 = f1 + f2" << endl;
    f3.print();
    cout << "f4 = f1 * f2" << endl;
    f4.print();

    if(f1 == f2) 
        cout << "Equal" << endl;
    else
        cout << "Not equal" << endl;
    
    Fraction f5 = ++f1;
    Fraction f6 = f2++;
    cout << "f5 = ++f1" << endl;
    cout << "Fraction 1" << endl;
    f1.print();
    cout << "Fraction 5" << endl;
    f5.print();
    cout << "f6 = f2++" << endl;
    cout << "Fraction 2" << endl;
    f2.print();
    cout << "Fraction 6" << endl;
    f6.print();

    cout << "Fraction 1" << endl;
    f1.print();
    cout << "Fraction 2" << endl;
    f2.print();
    f1 += f2;
    cout << "f1 += f2" << endl;
    cout << "Fraction 1" << endl;
    f1.print();
}