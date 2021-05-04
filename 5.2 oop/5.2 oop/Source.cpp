#include <iostream>
#include <string>
#include <exception>
#include <math.h>
#include <sstream>

using namespace std;

class Empty
{};

class Error
{
	string message;
public:
	Error(string message)
		: message(message)
	{}
	string What() { return message; }
};

class E : public exception
{
	string message;
public:
	E(string message)
		: message(message)
	{}
	string What() { return message; }
};

double disc(double a, double b, double c)
{
	double d;
	d = b * b - 4. * a * c;
	return d;
}

string Roots1(double a, double b, double c)
{
	double d;
	d = disc(a, b, c);

	if (d < 0)
		throw 1;
	double x1 = 0;
	double x2 = 0;
	x1 = (-1. * b + sqrt(d)) / (2. * a);
	x2 = (-1. * b - sqrt(d)) / (2. * a);

	stringstream ss;
	ss << d << ";" << x1 << ";" << x2;
	//cout << d << ";" << x1 << ";" << x2 << endl;
	return ss.str();
}

string Roots2(double a, double b, double c) throw()
{
	double d;
	d = disc(a, b, c);

	if (d < 0)
		throw 1.0;
	double x1 = 0;
	double x2 = 0;
	x1 = (-1. * b + sqrt(d)) / (2. * a);
	x2 = (-1. * b - sqrt(d)) / (2. * a);

	stringstream ss;
	ss << d << ";" << x1 << ";" << x2;
	//cout << d << ";" << x1 << ";" << x2 << endl;
	return ss.str();
}

string Roots3(double a, double b, double c) throw(char)
{
	double d;
	d = disc(a, b, c);

	if (d < 0)
		throw '1';
	double x1 = 0;
	double x2 = 0;
	x1 = (-1. * b + sqrt(d)) / (2. * a);
	x2 = (-1. * b - sqrt(d)) / (2. * a);

	stringstream ss;
	ss << d << ";" << x1 << ";" << x2;
	//cout << d << ";" << x1 << ";" << x2 << endl;
	return ss.str();
}

string Roots4(double a, double b, double c) throw(Empty)
{
	double d;
	d = disc(a, b, c);

	if (d < 0)
		throw Empty();
	double x1 = 0;
	double x2 = 0;
	x1 = (-1. * b + sqrt(d)) / (2. * a);
	x2 = (-1. * b - sqrt(d)) / (2. * a);

	stringstream ss;
	ss << d << ";" << x1 << ";" << x2;
	//cout << d << ";" << x1 << ";" << x2 << endl;
	return ss.str();
}

string Roots5(double a, double b, double c) throw(Error)
{
	double d;
	d = disc(a, b, c);

	if (d < 0)
		throw Error("d < 0");
	double x1 = 0;
	double x2 = 0;
	x1 = (-1. * b + sqrt(d)) / (2. * a);
	x2 = (-1. * b - sqrt(d)) / (2. * a);

	stringstream ss;
	ss << d << ";" << x1 << ";" << x2;
	//cout << d << ";" << x1 << ";" << x2 << endl;
	return ss.str();
}

string Roots6(double a, double b, double c) throw(int)
{
	double d;
	d = disc(a, b, c);

	if (d < 0)
		throw E("d < 0");
	double x1 = 0;
	double x2 = 0;
	x1 = (-1. * b + sqrt(d)) / (2. * a);
	x2 = (-1. * b - sqrt(d)) / (2. * a);

	stringstream ss;
	ss << d << ";" << x1 << ";" << x2;
	//cout << d << ";" << x1 << ";" << x2 << endl;
	return ss.str();
}

void FU()
{
	cout << "unexpected error! - bad_exception" << endl;
	throw;
}

void FT()
{
	cout << "unknown error! - terminate" << endl;
	abort();
}

int main()
{
	//cout << "set_unexpected(FU);" << endl;
	//set_unexpected(FU);

	//cout << "set_terminate(FT);" << endl;
	//set_terminate(FT);
	//try
	//{
	//	throw 1.0; // згенерували виняток
	//}
	//catch (bad_exception)
	//{
	//	cout << " catch (bad_exception)" << endl;
	//}

	//return 0;


	int a, b, c;

	for (int i = 0; i < 6; i++)
	{
		cout << " a = ? "; cin >> a;
		cout << " b = ? "; cin >> b;
		cout << " c = ? "; cin >> c;

		try
		{
			if (i == 0)
			{
				cout << Roots1(a, b, c) << endl;
			}
			else if (i == 1)
			{
				cout << Roots2(a, b, c) << endl;
			}
			else if (i == 2)
			{
				cout << Roots3(a, b, c) << endl;
			}
			else if (i == 3)
			{
				cout << Roots4(a, b, c) << endl;
			}
			else if (i == 4)
			{
				cout << Roots5(a, b, c) << endl;
			}
			else
			{
				cout << Roots6(a, b, c) << endl;
			}
		}
		catch (int)
		{
			cout << " catch (int) <= Roots1()" << endl;
		}
		catch (double)
		{
			cout << " catch (double) <= Roots2()" << endl;
		}
		catch (char)
		{
			cout << " catch (char) <= Roots3()" << endl;
		}
		catch (Empty)
		{
			cout << " catch (Empty) <= Roots4()" << endl;
		}
		catch (Error e)
		{
			cout << " catch (Error) <= Roots5() :" << endl;
			cout << e.What() << endl;
		}
		catch (bad_exception)
		{
			cout << " catch (bad_exception)" << endl;
		}
		catch (exception)
		{
			cout << " catch (exception) <= Roots6() :" << endl;
		}
		catch (E e)
		{
			cout << " catch (E) <= Roots6() :" << endl;
			cout << e.What() << endl;
		}

	}


	system("pause");

	return 0;
}