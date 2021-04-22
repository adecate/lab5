#pragma once
#include <iostream>
#include <cmath>

class Complex
{
private:
	double re;
	double im;
public:
	Complex(double, double);
	Complex(double);
	Complex();

	double Re() const;
	double Im() const;
	double R() const;
	double Phi() const;
	double cosh(Complex z) const;
	double exp(Complex z) const;

	friend std::ostream& operator<<(std::ostream& out, const Complex& ex);
	friend std::istream& operator>>(std::istream& in, Complex& ex);

	Complex operator+(Complex& expr);
	Complex operator+(const int& expr) const;
	Complex operator+=(Complex& expr);
	Complex operator-() const;
	Complex operator-(Complex& expr);
	Complex operator-=(Complex& expr);
	Complex operator*(Complex& expr);
	Complex operator*(const int& expr);
	Complex operator*=(Complex& expr);
	Complex operator/(Complex& expr);
	Complex operator/(const int& ex) const;
	Complex operator/=(Complex& expr);
};

Complex exp(const Complex& z);
Complex cosh(const Complex& z);
Complex sinh(const Complex& z);
