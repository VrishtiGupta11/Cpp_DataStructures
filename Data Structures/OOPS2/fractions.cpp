#include <iostream>
using namespace std;

class Fractions {
    private:
        int numerator;
        int denominator;
    public:
        Fractions() {}
        Fractions(int numerator, int denominator) {
            this->numerator = numerator;
            this->denominator = denominator;
        }
        int getNumerator() const {
            return this->numerator;
        }
        int getDenominator() const {
            return this->denominator;
        }
        void setNumerator(int numerator) {
            this->numerator = numerator;
        }
        void setDenominator(int denominator) {
            this->denominator = denominator;
        }
        void display() {
            cout << numerator << "/" << denominator << endl;
        }
        void addFractions(Fractions f1) {
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
};