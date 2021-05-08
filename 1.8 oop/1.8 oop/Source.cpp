// Source.cpp
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif // !#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
	Fraction f;
	Fraction::DigitString ds;

	cout << "DigitString : " << endl;
	cout << "ds.Read() : " << endl;
	ds.Read();
	cout << "ds.Display() : " << endl;
	ds.Display();
	//cout << ds.GetNum() << endl;
	cout << "ds.toString() : " << ds.toString() << endl;

	Fraction::DigitString ds1, ds2;
	cout << "ds1.Init(""10"") " << endl;
	ds1.Init("10");
	cout << "ds2.Init(""20"") " << endl;
	ds2.Init("20");
	cout << "Add(ds1, ds2).toString() : " << Add(ds1, ds2).toString() << endl;
	cout << "Sub(ds1, ds2).toString() : " << Sub(ds1, ds2).toString() << endl;
	cout << "Mul(ds1, ds2).toString() : " << Mul(ds1, ds2).toString() << endl;
	cout << "Div(ds1, ds2).toString() : " << Div(ds1, ds2).toString() << endl;
	cout << "Compare(ds1, ds2) : "
		<< (Compare(ds1, ds2) == 0 ? "ds1 < ds2" : (Compare(ds1, ds2) == 1 ? "ds1 > ds2" : "ds1 == ds2")) << endl;
	cout << endl;


	cout << "Fraction : " << endl;
	cout << ".Init(""10"", 50) : " << endl;
	f.Init("10", 50);
	//cout << ".Read() : " << endl;
	//f.Read();
	cout << ".Display() : " << endl;
	f.Display();
	cout << ".toString() : " << f.toString() << endl;

	Fraction f1, f2;
	cout << "f1.Init(""10"", 2) " << endl;
	f1.Init("10", 2);
	cout << "f2.Init(""20"", 5) " << endl;
	f2.Init("20", 5);
	cout << "Add(f1, f2).toString() : " << Add(f1, f2).toString() << endl;
	cout << "Sub(f1, f2).toString() : " << Sub(f1, f2).toString() << endl;
	cout << "Mul(f1, f2).toString() : " << Mul(f1, f2).toString() << endl;
	cout << "Div(f1, f2).toString() : " << Div(f1, f2).toString() << endl;
	cout << "Compare(f1, f2) : "
		<< (Compare(f1, f2) == 0 ? "f1 < f2" : (Compare(f1, f2) == 1 ? "f1 > f2" : "f1 == f2")) << endl;
	cout << endl;

	cin.get();
	return 0;
}