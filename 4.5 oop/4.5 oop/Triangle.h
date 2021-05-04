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
public:
	virtual void Print() = 0;
	virtual double Square() = 0;
	virtual double Perimeter() = 0;

};
