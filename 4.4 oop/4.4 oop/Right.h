// Right.h
#pragma once

#include "Triangle.h"

class Right :
	public Triangle
{
public:
	Right(void);
	Right(int ab, int bc, int angle);
	~Right(void);

	virtual void Print();
	virtual void Input();
	virtual double Square();
	virtual double Perimeter();

	virtual ostream& Print(ostream& out) const;
	virtual istream& Input(istream& in);
};