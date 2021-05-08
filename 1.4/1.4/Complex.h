// Сomplex.h
#pragma once

#include <string>

using namespace std;

class Complex
{
private:
	double re, im;

public:
	double GetRe() const { return re; }
	double GetIm() const { return im; }
	void SetRe(double value) { re = value; }
	void SetIm(double value) { im = value; }

	void Init(double, double);
	void Read(const char*);
	void Display();

	string toString() const;

	friend Complex Add(const Complex& a, const Complex& b);
	friend Complex Sub(const Complex& a, const Complex& b);
	friend Complex Mul(const Complex& a, const Complex& b);

};
