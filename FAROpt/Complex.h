#pragma once
class Complex {
public:
	Complex();
	Complex(double re, double im);
	Complex& operator+(const Complex);
	Complex& operator+=(const Complex);
	Complex& operator-(const Complex);
	Complex& operator-();
	Complex& operator*(const double);
	Complex& operator*(const Complex);
	Complex& operator/(const double);
	Complex& operator/(const Complex);
	Complex& conj();
	Complex& inverse();
	double abs();
	double tgArg();
	double cosArg();
	double sinArg();
	double arg();
	double Re();
	double Im();

private:
	double _re;
	double _im;
};

