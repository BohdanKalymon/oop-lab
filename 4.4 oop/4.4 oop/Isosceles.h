// Isosceles.h
#pragma once

#include "Triangle.h"

class Isosceles :
	public Triangle
{
public:
	Isosceles(void);
	Isosceles(int ab, int bc, int angle);
	~Isosceles(void);

	virtual void Print();
	virtual void Input();
	virtual double Square();
	virtual double Perimeter();

	virtual ostream& Print(ostream& out) const;
	virtual istream& Input(istream& in);
};
