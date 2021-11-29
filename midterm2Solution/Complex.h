/*
part 1
operator+ 4 marks 
operator- 4 marks
operaator++ 4marks
friend Method call 1 mark 
friend Method call 1 mark 
operator<< 3marks
operator>> 3marks
*/

#include <iostream>

using namespace std;

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
   private:
    double a;
    double b;

   public:
    Complex() {
        a = 0;
        b = 0;
    }

    Complex(double _a, double _b) {
        a = _a;
        b = _b;
    }

    double getA() const {
        return a;
    }

    double getB() const {
        return b;
    }

    Complex& operator+(const Complex& secondComplex) {
        // 4 points

        double newA = this->a + secondComplex.getA();
        double newB = this->b + secondComplex.getB();
        Complex* result = new Complex(newA, newB);
        return *result;
    }

    Complex& operator-(const Complex& secondComplex) {
        // 4 points

        double newA = this->a - secondComplex.getA();
        double newB = this->b - secondComplex.getB();
        Complex* result = new Complex(newA, newB);
        return *result;
    }

    Complex& operator++(int i) {
        // 4 points

        Complex* old = new Complex(this->a, this->b);

        this->a++;

        return *old;
    }

    // 1 point
    friend ostream& operator<<(ostream& out, const Complex& right);
    // 1 point
    friend istream& operator>>(istream& in, Complex& right);
};

ostream& operator<<(ostream& out, const Complex& right) {
    // 3 points

    if (right.b != 0) {
        out << right.a << " + " << right.b << "i" << endl;
    } else {
        out << right.a << endl;
    }
    return out;
}

istream& operator>>(istream& in, Complex& right) {
    // 3 points

    cout << "Enter the real part:" << endl;
    in >> right.a;
    cout << "Enter imaginary part" << endl;
    in >> right.b;
    return in;
}

#endif