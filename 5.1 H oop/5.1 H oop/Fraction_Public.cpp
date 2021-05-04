// Fraction_Public.cpp
#include "Fraction_Public.h"
#include <sstream>
#include <iostream>

using namespace std;

string Fraction_Public::toString() const
{
	stringstream sout;
	sout << this->GetNum() << "." << GetFrac();
	return sout.str();
};

float Fraction_Public::toFloat() const
{
	stringstream sout;
	sout << this->GetNum() << "." << GetFrac();
	return (float)atof(sout.str().c_str());
};

void Fraction_Public::Init(string exp, unsigned int frac)
{
	this->SetNum(exp);
	SetFrac(frac);
}

void Fraction_Public::Read()
{
	DigitString exp;
	unsigned int frac;
	exp.Read();
	cout << "	Number.frac = ? "; cin >> frac;
	Init(exp.GetNum(), frac);
}

void Fraction_Public::Display()
{
	cout << toString() << endl;
}

Fraction_Public Add(const Fraction_Public& a, const Fraction_Public& b)
{
	Fraction_Public r;
	stringstream sout;
	string e;
	unsigned int f;

	float d = a.toFloat() + b.toFloat();
	sout << d;
	string s = sout.str();
	int i = (int)s.find('.');
	e = s.substr(0, i);
	f = atoi((s.substr(++i, s.length() - 1)).c_str());
	r.Init(e, f);
	return r;
}

Fraction_Public Sub(const Fraction_Public& a, const Fraction_Public& b)
{
	Fraction_Public r;
	stringstream sout;
	string e;
	unsigned int f;

	float d = a.toFloat() - b.toFloat();
	sout << d;
	string s = sout.str();
	int i = (int)s.find('.');
	e = s.substr(0, i);
	f = atoi((s.substr(++i, s.length() - 1)).c_str());
	r.Init(e, f);
	return r;
}

Fraction_Public Mul(const Fraction_Public& a, const Fraction_Public& b)
{
	Fraction_Public r;
	stringstream sout;
	string e;
	unsigned int f;

	float d = a.toFloat() * b.toFloat();
	sout << d;
	string s = sout.str();
	int i = (int)s.find('.');
	e = s.substr(0, i);
	f = atoi((s.substr(++i, s.length() - 1)).c_str());
	r.Init(e, f);
	return r;
}

Fraction_Public Div(const Fraction_Public& a, const Fraction_Public& b)
{
	Fraction_Public r;
	stringstream sout;
	string e;
	unsigned int f;

	float d = a.toFloat() / b.toFloat();
	sout << d;
	string s = sout.str();
	int i = (int)s.find('.');
	e = s.substr(0, i);
	f = atoi((s.substr(++i, s.length() - 1)).c_str());
	r.Init(e, f);
	return r;
}

int Compare(const Fraction_Public& a, const Fraction_Public& b)
{
	if (a.toFloat() < b.toFloat())
		return 0;
	else if (a.toFloat() > b.toFloat())
		return 1;
	else
		return -1;

}

Fraction_Public& Fraction_Public::operator --() // префіксний декремент
{
	--frac; // модифікували поточний об'єкт
	return *this; // повернули модифікований об'єкт
}

Fraction_Public& Fraction_Public::operator ++() // префіксний інкремент
{
	++frac; // модифікували поточний об'єкт
	return *this; // повернули модифікований об'єкт
}

Fraction_Public Fraction_Public::operator --(int) // постфіксний декремент
{
	Fraction_Public a(*this); // створили копію
	frac--; // модифікували поточний об'єкт
	return a; // повернули копію
}

Fraction_Public Fraction_Public::operator ++(int) // постфіксний інкремент
{
	Fraction_Public a(*this); // створили копію
	frac++; // модифікували поточний об'єкт
	return a; // повернули копію
}

ostream& operator <<(ostream& out, const Fraction_Public& f)
{
	return out << f.toString();
}

istream& operator >>(istream& in, Fraction_Public& f) throw(const char*)
{
	DigitString exp;
	unsigned int frac;
	in >> exp;
	f.SetExp(exp);
	cout << ".frac ? = "; in >> frac;

	if (frac == 100)
	{
		cout << "By value : ";
		throw invalid_argument("invalid_agrument");
	}
	else if (frac == 101)
	{
		cout << "By pointer : ";
		throw "exception";
	}
	else if (frac == 102)
	{
		cout << "By reference : ";
		throw bad_exception();
	}

	f.SetFrac(frac);

	return in;
}

Fraction_Public& Fraction_Public::operator =(const Fraction_Public& f)
{
	SetExp(f.GetExp());
	SetFrac(f.GetFrac());
	return *this; // повернули посилання на поточний об’єкт
}

Fraction_Public::operator string() const
{
	return toString();
}

Fraction_Public operator +(const Fraction_Public& a, const Fraction_Public& b)
{
	Fraction_Public r;
	stringstream sout;
	string e;
	unsigned int f;

	float d = a.toFloat() + b.toFloat();
	sout << d;
	string s = sout.str();
	int i = (int)s.find('.');
	e = s.substr(0, i);
	f = atoi((s.substr(++i, s.length() - 1)).c_str());
	r.Init(e, f);
	return r;
}

Fraction_Public operator -(const Fraction_Public& a, const Fraction_Public& b)
{
	Fraction_Public r;
	stringstream sout;
	string e;
	unsigned int f;

	float d = a.toFloat() - b.toFloat();
	sout << d;
	string s = sout.str();
	int i = (int)s.find('.');
	e = s.substr(0, i);
	f = atoi((s.substr(++i, s.length() - 1)).c_str());
	r.Init(e, f);
	return r;
}

Fraction_Public operator *(const Fraction_Public& a, const Fraction_Public& b)
{
	Fraction_Public r;
	stringstream sout;
	string e;
	unsigned int f;

	float d = a.toFloat() * b.toFloat();
	sout << d;
	string s = sout.str();
	int i = (int)s.find('.');
	e = s.substr(0, i);
	f = atoi((s.substr(++i, s.length() - 1)).c_str());
	r.Init(e, f);
	return r;
}

Fraction_Public operator /(const Fraction_Public& a, const Fraction_Public& b)
{
	Fraction_Public r;
	stringstream sout;
	string e;
	unsigned int f;

	float d = a.toFloat() / b.toFloat();
	sout << d;
	string s = sout.str();
	int i = (int)s.find('.');
	e = s.substr(0, i);
	f = atoi((s.substr(++i, s.length() - 1)).c_str());
	r.Init(e, f);
	return r;
}

bool operator ==(Fraction_Public& a, Fraction_Public& b)
{
	return a.toFloat() == b.toFloat();
}

bool operator !=(Fraction_Public& a, Fraction_Public& b)
{
	return a.toFloat() != b.toFloat();
}

bool operator >=(Fraction_Public& a, Fraction_Public& b)
{
	return a.toFloat() >= b.toFloat();
}

bool operator >(Fraction_Public& a, Fraction_Public& b)
{
	return a.toFloat() > b.toFloat();
}

bool operator <=(Fraction_Public& a, Fraction_Public& b)
{
	return a.toFloat() <= b.toFloat();
}

bool operator <(Fraction_Public& a, Fraction_Public& b)
{
	return a.toFloat() < b.toFloat();
}