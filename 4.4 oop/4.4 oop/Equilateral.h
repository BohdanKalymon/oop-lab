// Equilateral.h
#pragma once

#include "Triangle.h"

class Equilateral :
	public Triangle
{
public:
	Equilateral(void);
	Equilateral(int ab, int bc, int angle);
	~Equilateral(void);

	virtual void Print();
	virtual void Input();
	virtual double Square();
	virtual double Perimeter();

	virtual ostream& Print(ostream& out) const;
	virtual istream& Input(istream& in);
};