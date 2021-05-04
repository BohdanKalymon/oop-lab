// Triangle.h
#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

class Triangle
{
	int ab, bc, angle;

public:
	Triangle(void);
	Triangle(int ab, int bc, int angle);

	void setAB(int v = 0) { this->ab = v; }
	int getAB() const { return ab; }
	void setBC(int v = 0) { this->bc = v; }
	int getBC() const { return bc; }
	void setAngle(int v = 0) { this->angle = v; }
	int getAngle() const { return angle; }

	~Triangle(void);

	virtual void Print() = 0;
	virtual void Input() = 0;
	virtual double Square() = 0;
	virtual double Perimeter() = 0;

	virtual ostream& Print(ostream& out) const = 0;
	virtual istream& Input(istream& in) = 0;
};