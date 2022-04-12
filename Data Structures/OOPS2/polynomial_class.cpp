#include <iostream>
using namespace std;

class Polynomial{
    int* degCoeff;
    int capacity;
public:
    // Default Constructor
    Polynomial() {
        degCoeff = new int[10]{0};
        capacity = 10;
    }
    // Copy Contructor
    Polynomial(Polynomial &p) {
        this->degCoeff = new int[p.capacity];
        for(int i=0; i<p.capacity; i++) {
            this->degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
    }
    // Copy assignment operator
    // Polynomial operator=(Polynomial &p) {
    //     this->degCoeff = new int[p.capacity];
    //     for(int i=0; i<p.capacity; i++) {
    //         this->degCoeff[i] = p.degCoeff[i];
    //     }
    //     this->capacity = p.capacity;
    // }

    // overload + operator
    Polynomial operator+(Polynomial const &p2) {
        Polynomial* newPoly = new Polynomial;
        newPoly->capacity = (this->capacity > p2.capacity) ? this->capacity : p2.capacity;
        newPoly->degCoeff = new int[newPoly->capacity];
        for(int i=0; i<newPoly->capacity; i++)
            newPoly->degCoeff[i] = this->degCoeff[i] + p2.degCoeff[i];
        return *newPoly;
    }

    // overload - operator
    Polynomial operator-(Polynomial &p2) {
        Polynomial* newPoly = new Polynomial;
        newPoly->capacity = (this->capacity > p2.capacity) ? this->capacity : p2.capacity;
        newPoly->degCoeff = new int[newPoly->capacity];
        for(int i=0; i<newPoly->capacity; i++)
            newPoly->degCoeff[i] = this->degCoeff[i] - p2.degCoeff[i];
        return *newPoly;
    }

    // set coefficient
    void setCoefficient(int degree, int coeff) {
        if(degree >= capacity) {
            int* newDegcoeff = new int[degree+1]{0};
            for(int i=0; i<capacity; i++)
                newDegcoeff[i] = degCoeff[i];
            delete [] degCoeff;
            degCoeff = newDegcoeff;
            capacity = degree+1;
        }
        degCoeff[degree] = coeff;
    }

    // overload * operator
    Polynomial operator*(Polynomial &p2) {
        Polynomial* newPoly = new Polynomial;
        newPoly->capacity = this->capacity + p2.capacity;
        newPoly->degCoeff = new int[newPoly->capacity]{0};
        for(int i=0; i<capacity; i++) {
            // if(degCoeff[i]==0)
            //     continue;
            for(int j=0; j<p2.capacity; j++) {
                // if(newPoly->degCoeff[j]==0)
                //     continue;
                // newPoly->setCoefficient(i+j, (degCoeff[i])*(p2.degCoeff[j]));
                newPoly->degCoeff[i+j] += (degCoeff[i])*(p2.degCoeff[j]);
            }
        }
        return *newPoly;
    }

    // Print
    void print() {
        for(int i=0; i<capacity; i++) {
            if(degCoeff[i] != 0) {
                if(degCoeff[i] > 0)
                    cout << "+";
                cout << degCoeff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }

    
};

int main() {
    Polynomial p1;
    p1.setCoefficient(2, 3);
    p1.setCoefficient(5, 4);
    p1.setCoefficient(7, -1);
    p1.print();
    Polynomial p2;
    p2.setCoefficient(2, 3);
    p2.setCoefficient(5, 4);
    p2.setCoefficient(7, -1);
    p1.print();
    Polynomial p3;
    p3 = p1*p2;
    p3.print();
}