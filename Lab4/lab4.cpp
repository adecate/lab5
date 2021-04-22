#include <iostream>
#include <cmath>   

using namespace std;

class Complex

{

private:

	double r;
	double phi;

public:

	Complex operator -(const Complex& s2)

	{

		Complex s;

		s.r = this->r - s2.r;

		s.phi = this->phi - s2.phi;

		return s;

	}

	Complex operator *(const Complex& s2)

	{

		Complex s;

		s.r = this->r * s2.r - this->phi * s2.phi;

		s.phi = this->r * s2.phi + this->phi * s2.phi;

		return s;

	}

	Complex()

	{

		r = 0;

		phi = 0;

	}

	Complex(float r, float phi)

	{

		this->r = r;
		this->phi = phi;

	}

	Complex th()

	{

		Complex result;

		result.r = tanh(r);
		result.phi = tanh(phi);

		return result;

	}

	void vvod()

	{

		cout << "Re:"; cin >> r;
		cout << "Im:"; cin >> phi;

	}

	void vivod()

	{

		cout << "Re:" << r << endl;
		cout << "Im:" << phi << endl;

	}

};

void main(void) 
{

	Complex z, y;

	cout << "enter complex numbers:" << endl;

	z.vvod();

	y = 1 - pow(z, Complex(5,0)) * (z / Complex(2, 0)).th();

	cout << "result y(z) = 1 − z^5 − th(z/2)" << endl;

	y.vivod();

}