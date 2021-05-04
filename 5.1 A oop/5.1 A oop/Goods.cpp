// Goods.cpp

#include "Goods.h"
#include <iostream>
#include <sstream>

using namespace std;

double Goods::GetFirst() const
{
	return first;
}

int Goods::GetSecond() const
{
	return second;
}

bool Goods::SetFirst(double value)
{
	if (value >= 0)
	{
		first = value;
		return true;
	}
	else
	{
		first = 0;
		return false;
	}
}

bool Goods::SetSecond(int value)
{
	if (value >= 0)
	{
		second = value;
		return true;
	}
	else
	{
		second = 0;
		return false;
	}
}

bool Goods::Init(double f, int s)
{
	if (SetFirst(f) && SetSecond(s))
	{
		return true;
	}
	else
	{
		return false;
	}

}

void Goods::Read()
{
	double f;
	int s;

	do
	{
		cout << "first  = ? "; cin >> f;
		cout << "second = ? "; cin >> s;
	} while (!Init(f, s));

}

void Goods::Display()
{
	cout << "first  = " << first << endl;
	cout << "second = " << second << endl;
}

double Goods::cost()
{
	return first * second;
}



Goods& Goods::operator --() // префіксний декремент
{
	--first; // модифікували поточний об'єкт
	return *this; // повернули модифікований об'єкт
}
Goods& Goods::operator ++() // префіксний інкремент
{
	++first; // модифікували поточний об'єкт
	return *this; // повернули модифікований об'єкт
}
Goods Goods::operator --(int) // постфіксний декремент
{
	Goods a(*this); // створили копію
	second--; // модифікували поточний об'єкт
	return a; // повернули копію
}

Goods Goods::operator ++(int) // постфіксний інкремент
{
	Goods a(*this); // створили копію
	second++; // модифікували поточний об'єкт
	return a; // повернули копію
}

ostream& operator <<(ostream& out, const Goods& g)
{
	return out << "	First : " << g.GetFirst() << endl
		<< "	Second : " << g.GetSecond() << endl;
}

istream& operator >>(istream& in, Goods& g) throw(const char*, bad_exception&)
{
	double f;
	int s;
	cout << ".first = "; in >> f;
	g.SetFirst(f);
	cout << ".second = "; in >> s;

	if (f < 0 && s < 0)
	{
		cout << "By value : ";
		throw invalid_argument("invalid_agrument");
	}
	else if (f < 0)
	{
		cout << "By pointer : ";
		throw "exception";
	}
	else if (s < 0)
	{
		//throw "Error - second < 0";
		cout << "By reference : ";
		throw bad_exception();
	}

	g.SetSecond(s);
	cout << endl;

	return in;
}

Goods& Goods::operator =(const Goods& g)
{
	first = g.first; // змінили поле поточного об’єкта
	second = g.second; // змінили поле поточного об’єкта
	return *this; // повернули посилання на поточний об’єкт
}

Goods::operator string() const
{
	stringstream sout;
	sout << "	First : " << GetFirst() << endl
		<< "	Second : " << GetSecond()
		;
	return sout.str();
}

string Goods::toString() const
{
	stringstream sout;
	sout << "	First : " << GetFirst() << endl
		<< "	Second : " << GetSecond()
		;
	return sout.str();
}