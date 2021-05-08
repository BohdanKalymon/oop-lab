// Source.cpp
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
	Complex z;
	z.Read("z1");
	cout << "Display z1";
	z.Display();
	cout << "z1.toString() : " << z.toString() << endl;

	Complex z2;
	z2.Read("z2");
	cout << "Display z2" << endl;
	z2.Display();
	cout << "z2.toString() : " << z2.toString() << endl;

	//cout << "\nAdd(z1, z2)\nDisplay Result :";
	//Add(z, z2).Display();
	cout << "Add(z1, z2) = " << Add(z, z2).toString() << endl;
	//cout << "\nSub(z1, z2)\nDisplay Result :";
	//Sub(z, z2).Display();
	cout << "Sub(z1, z2) = " << Sub(z, z2).toString() << endl;
	//cout << "\nMul(z1, z2)\nDisplay Result :";
	//Mul(z, z2).Display();
	cout << "Mul(z1, z2) = " << Mul(z, z2).toString() << endl;

	cin.get();

	return 0;
}