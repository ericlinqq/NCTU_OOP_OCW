// Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H

/* Write class definition for Complex including constructors*/
class Complex
{
private:
    double real;
    double image;

public:
    Complex();
    Complex(double, double);
    Complex(Complex&);
    void assign(double, double);
    void assignReal(double);
    void assignImage(double);
    void printComplex();
    

    Complex add(Complex);
    Complex subtract(Complex);
    Complex multiply(Complex);
    Complex division(Complex);

    Complex operator + (const Complex &);
    Complex operator - (const Complex &);
    Complex operator * (const Complex &);
    Complex operator / (const Complex &);
    Complex operator - ();
    void setComplexNumber(double, double);

    friend void printMeg(const Complex &, const Complex &, char);
    friend void printComplex(const Complex &);

};

#endif
