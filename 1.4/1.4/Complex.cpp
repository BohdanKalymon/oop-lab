// Complex.cpp

#include "Complex.h"
#include <iostream>
//#include <cmath>
#include <sstream> // підключаємо бібліотеку, яка описує літерні потоки

using namespace std;

void Complex::Display()
{
	cout << endl;
	cout << " Re = " << re << endl;
	cout << " Im = " << im << endl;
}

void Complex::Init(double x, double y)
{
	re = x;
	im = y;
}

void Complex::Read(const char* text)
{
	double x, y;
	cout << "Input complex value " << text << ":" << endl;
	cout << " Re = "; cin >> x;
	cout << " Im = "; cin >> y;
	Init(x, y);
}

string Complex::toString() const
{
	stringstream sout;
	sout << GetRe() << " + i * " << GetIm();
	return sout.str();
}

Complex Add(const Complex& a, const Complex& b) {
	Complex r;
	r.SetRe(a.GetRe() + b.GetRe());
	r.SetIm(a.GetIm() + b.GetIm());
	return r;
}

Complex Sub(const Complex& a, const Complex& b) {
	Complex r;
	r.SetRe(a.GetRe() - b.GetRe());
	r.SetIm(a.GetIm() - b.GetIm());
	return r;
}

Complex Mul(const Complex& a, const Complex& b) {
	Complex r;
	double x, y;
	x = a.GetRe() * b.GetRe() - a.GetIm() * b.GetIm();
	y = a.GetRe() * b.GetIm() + b.GetRe() * a.GetIm();
	r.Init(x, y);
	//r.SetRe(x);
	//r.SetIm(y);
	return r;
}