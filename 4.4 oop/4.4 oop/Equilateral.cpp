// Equilateral.cpp
#include "Equilateral.h"

Equilateral::Equilateral(void)
{}

Equilateral::Equilateral(const int ab = 0, const int bc = 0, const int angle = 0)
	: Triangle(ab, bc, angle)
{}

Equilateral::~Equilateral(void)
{}

void Equilateral::Print()
{
	cout //<< typeid(*this).name() << " : "
		<< "AB = " << Triangle::getAB() << ", BC = " << Triangle::getBC() << ", Angle = " << fixed << setprecision(2) << Triangle::getAngle() << "'" << endl;
}

void Equilateral::Input()
{
	int n;

	cout << "AB, mm ? = "; cin >> n;
	setAB(n);
	cout << "BC, mm ? = "; cin >> n;
	setBC(n);
	cout << "Angle, ' ? = "; cin >> n;
	setAngle(n);
}

double Equilateral::Square()//S = 0.5 * ab * bc * sin(angle)
{
	double S = 0.5 * getAB() * getBC() * sin((3.1415926536 / 180) * getAngle());
	return S;
}

double Equilateral::Perimeter()//ca = sqrt(ab*ab + bc*bc - 2*ab*bc*cos(angle)) ; P = ab + bc + ca 
{
	double ca = sqrt(1. * getAB() * getAB() + 1. * getBC() * getBC() - 2. * getAB() * getBC() * cos((3.1415926536 / 180) * getAngle()));
	double P = getAB() + getBC() + ca;
	return P;
}

ostream& Equilateral::Print(ostream& out) const
{
	return out << "AB = " << getAB() << ", BC = " << getBC() << ", Angle = " << fixed << setprecision(2) << getAngle() << "'" << endl;
}

istream& Equilateral::Input(istream& in)
{
	int n;

	cout << "AB, mm ? = "; in >> n;
	setAB(n);
	cout << "BC, mm ? = "; in >> n;
	setBC(n);
	cout << "Angle, ' ? = "; in >> n;
	setAngle(n);

	return in;
}