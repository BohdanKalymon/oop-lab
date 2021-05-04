// Fraction_Private.cpp
#include "Fraction_Private.h"
#include <sstream>
#include <iostream>

using namespace std;

string Fraction_Private::toString() const
{
	stringstream sout;
	sout << this->GetNum() << "." << GetFrac();
	return sout.str();
};

float Fraction_Private::toFloat() const
{
	stringstream sout;
	sout << this->GetNum() << "." << GetFrac();
	return (float)atof(sout.str().c_str());
};

void Fraction_Private::Init(string exp, unsigned int frac)
{
	this->SetNum(exp);
	SetFrac(frac);
}

void Fraction_Private::Read()
{
	DigitString exp;
	unsigned int frac;
	exp.Read();
	cout << "	Number.frac = ? "; cin >> frac;
	Init(exp.GetNum(), frac);
}

void Fraction_Private::Display()
{
	cout << toString() << endl;
}

Fraction_Private Add(const Fraction_Private& a, const Fraction_Private& b)
{
	Fraction_Private r;
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

Fraction_Private Sub(const Fraction_Private& a, const Fraction_Private& b)
{
	Fraction_Private r;
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

Fraction_Private Mul(const Fraction_Private& a, const Fraction_Private& b)
{
	Fraction_Private r;
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

Fraction_Private Div(const Fraction_Private& a, const Fraction_Private& b)
{
	Fraction_Private r;
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

int Compare(const Fraction_Private& a, const Fraction_Private& b)
{
	if (a.toFloat() < b.toFloat())
		return 0;
	else if (a.toFloat() > b.toFloat())
		return 1;
	else
		return -1;

}

Fraction_Private& Fraction_Private::operator --() // префіксний декремент
{
	--frac; // модифікували поточний об'єкт
	return *this; // повернули модифікований об'єкт
}

Fraction_Private& Fraction_Private::operator ++() // префіксний інкремент
{
	++frac; // модифікували поточний об'єкт
	return *this; // повернули модифікований об'єкт
}

Fraction_Private Fraction_Private::operator --(int) // постфіксний декремент
{
	Fraction_Private a(*this); // створили копію
	frac--; // модифікували поточний об'єкт
	return a; // повернули копію
}

Fraction_Private Fraction_Private::operator ++(int) // постфіксний інкремент
{
	Fraction_Private a(*this); // створили копію
	frac++; // модифікували поточний об'єкт
	return a; // повернули копію
}

ostream& operator <<(ostream& out, const Fraction_Private& f)
{
	return out << f.toString();
}

istream& operator >>(istream& in, Fraction_Private& f) throw(const char*)
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

Fraction_Private& Fraction_Private::operator =(const Fraction_Private& f)
{
	SetExp(f.GetExp());
	SetFrac(f.GetFrac());
	return *this; // повернули посилання на поточний об’єкт
}

Fraction_Private::operator string() const
{
	return toString();
}

Fraction_Private operator +(const Fraction_Private& a, const Fraction_Private& b)
{
	Fraction_Private r;
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

Fraction_Private operator -(const Fraction_Private& a, const Fraction_Private& b)
{
	Fraction_Private r;
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

Fraction_Private operator *(const Fraction_Private& a, const Fraction_Private& b)
{
	Fraction_Private r;
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

Fraction_Private operator /(const Fraction_Private& a, const Fraction_Private& b)
{
	Fraction_Private r;
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

bool operator ==(Fraction_Private& a, Fraction_Private& b)
{
	return a.toFloat() == b.toFloat();
}

bool operator !=(Fraction_Private& a, Fraction_Private& b)
{
	return a.toFloat() != b.toFloat();
}

bool operator >=(Fraction_Private& a, Fraction_Private& b)
{
	return a.toFloat() >= b.toFloat();
}

bool operator >(Fraction_Private& a, Fraction_Private& b)
{
	return a.toFloat() > b.toFloat();
}

bool operator <=(Fraction_Private& a, Fraction_Private& b)
{
	return a.toFloat() <= b.toFloat();
}

bool operator <(Fraction_Private& a, Fraction_Private& b)
{
	return a.toFloat() < b.toFloat();
}