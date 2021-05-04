// Right.cpp
#include "Right.h"

Right::Right(void)
{}

Right::Right(const int ab = 0, const int bc = 0, const int angle = 0)
{
	this->ab = ab;
	this->bc = bc;
	this->angle = angle;
}

Right::~Right(void)
{}

void Right::Print()
{
	cout //<< typeid(*this).name() << " : "
		<< "AB = " << getAB() << ", BC = " << getBC() << ", Angle = " << fixed << setprecision(2) << getAngle() << "'" << endl;
}

double Right::Square()//S = 0.5 * ab * bc * sin(angle)
{
	double S = 0.5 * getAB() * getBC() * sin((3.1415926536 / 180) * getAngle());
	return S;
}

double Right::Perimeter()//ca = sqrt(ab*ab + bc*bc - 2*ab*bc*cos(angle)) ; P = ab + bc + ca 
{
	double ca = sqrt(1. * getAB() * getAB() + 1. * getBC() * getBC() - 2. * getAB() * getBC() * cos((3.1415926536 / 180) * getAngle()));
	double P = getAB() + getBC() + ca;
	return P;
}