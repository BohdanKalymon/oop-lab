// Equilateral.h
#pragma once

#include "Triangle.h"

class Equilateral :
	public Triangle
{
	int ab, bc, angle;

public:
	void setAB(int v = 0) { this->ab = v; }
	int getAB() const { return ab; }
	void setBC(int v = 0) { this->bc = v; }
	int getBC() const { return bc; }
	void setAngle(int v = 0) { this->angle = v; }
	int getAngle() const { return angle; }

	Equilateral(void);
	Equilateral(int ab, int bc, int angle);
	~Equilateral(void);

	virtual void Print();
	virtual double Square();
	virtual double Perimeter();

};