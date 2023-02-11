// Complex.cpp
#include <iostream>
#include <iomanip>
using std::cout;


#include "Complex.h"

// Member-function definitions for class Complex.n
Complex::Complex() {
    real = 0.0;
    image = 0.0;
}

Complex::Complex(double r, double i) {
    real = r;
    image = i;
}

Complex::Complex(Complex &C) {
    real = C.real;
    image = C.image;
}

void Complex::assign(double r, double i) {
    real = r;
    image = i;
}

void Complex::assignReal(double r) {
    real = r;
}

void Complex::assignImage(double i) {
    image = i;
}

void Complex::printComplex() {
    cout << std::setprecision(2) << "(" << real << ", " << image << ")";
}

Complex Complex::add(Complex c) {
    Complex tmp;
    tmp.real = real + c.real;
    tmp.image = image + c.image;
    return tmp;
}

Complex Complex::subtract(Complex c) {
    Complex tmp;
    tmp.real = real - c.real;
    tmp.image = image - c.image;
    return tmp;
}

Complex Complex::multiply(Complex c) {
    Complex tmp;
    tmp.real = real * c.real - image * c.image;
    tmp.image = image * c.real + real * c.image;
    return tmp;
}

Complex Complex::division(Complex c) {
    Complex tmp;
    tmp.real = (real * c.real + image * c.image ) / (c.real * c.real + c.image * c.image);
    tmp.image = (image * c.real - real * c.image) / (c.real * c.real + c.image * c.image);
    return tmp;
}