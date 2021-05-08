// Fraction.cpp
#include "Fraction.h"
#include <sstream>
#include <iostream>

using namespace std;

string Fraction::toString() const
{
	stringstream sout;
	sout << exp.toString() << "." << GetFrac();
	return sout.str();
};

float Fraction::toFloat() const
{
	stringstream sout;
	sout << exp.GetNum() << "." << GetFrac();
	return atof(sout.str().c_str());
};

void Fraction::Init(string exp, unsigned int frac)
{
	this->exp.Init(exp);
	SetFrac(frac);
}

void Fraction::Read()
{
	DigitString exp;
	unsigned int frac;
	exp.Read();
	cout << "	Number.frac = ? "; cin >> frac;
	Init(exp.GetNum(), frac);
}

void Fraction::Display()
{
	cout << toString() << endl;
}

Fraction Add(const Fraction& a, const Fraction& b)
{
	Fraction r;
	stringstream sout;
	string e;
	unsigned int f;

	float d = a.toFloat() + b.toFloat();
	sout << d;
	string s = sout.str();
	int i = s.find('.');
	e = s.substr(0, i);
	f = atoi((s.substr(i + 1, s.length() - 1)).c_str());
	r.Init(e, f);
	return r;
}

Fraction Sub(const Fraction& a, const Fraction& b)
{
	Fraction r;
	stringstream sout;
	string e;
	unsigned int f;

	float d = a.toFloat() - b.toFloat();
	sout << d;
	string s = sout.str();
	int i = s.find('.');
	e = s.substr(0, i);
	f = atoi((s.substr(i + 1, s.length() - 1)).c_str());
	r.Init(e, f);
	return r;
}

Fraction Mul(const Fraction& a, const Fraction& b)
{
	Fraction r;
	stringstream sout;
	string e;
	unsigned int f;

	float d = a.toFloat() * b.toFloat();
	sout << d;
	string s = sout.str();
	int i = s.find('.');
	e = s.substr(0, i);
	f = atoi((s.substr(i + 1, s.length() - 1)).c_str());
	r.Init(e, f);
	return r;
}

Fraction Div(const Fraction& a, const Fraction& b)
{
	Fraction r;
	stringstream sout;
	string e;
	unsigned int f;

	float d = a.toFloat() / b.toFloat();
	sout << d;
	string s = sout.str();
	int i = s.find('.');
	e = s.substr(0, i);
	f = atoi((s.substr(i + 1, s.length() - 1)).c_str());
	r.Init(e, f);
	return r;
}

int Compare(const Fraction& a, const Fraction& b)
{
	if (a.toFloat() < b.toFloat())
		return 0;
	else if (a.toFloat() > b.toFloat())
		return 1;
	else
		return -1;

}

Fraction& Fraction::operator --() // префіксний декремент
{
	--frac; // модифікували поточний об'єкт
	return *this; // повернули модифікований об'єкт
}

Fraction& Fraction::operator ++() // префіксний інкремент
{
	++frac; // модифікували поточний об'єкт
	return *this; // повернули модифікований об'єкт
}

Fraction Fraction::operator --(int) // постфіксний декремент
{
	Fraction a(*this); // створили копію
	frac--; // модифікували поточний об'єкт
	return a; // повернули копію
}

Fraction Fraction::operator ++(int) // постфіксний інкремент
{
	Fraction a(*this); // створили копію
	frac++; // модифікували поточний об'єкт
	return a; // повернули копію
}

ostream& operator <<(ostream& out, const Fraction& f)
{
	return out << f.toString();
}

istream& operator >>(istream& in, Fraction& f)
{
	Fraction::DigitString exp;
	unsigned int frac;
	in >> exp;
	f.SetExp(exp);
	cout << ".frac ? = "; in >> frac;
	f.SetFrac(frac);
	return in;
}

Fraction& Fraction::operator =(const Fraction& f)
{
	SetExp(f.GetExp());
	SetFrac(f.GetFrac());
	return *this; // повернули посилання на поточний об’єкт
}

Fraction::operator string() const
{
	return toString();
}

Fraction operator +(const Fraction& a, const Fraction& b)
{
	Fraction r;
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

Fraction operator -(const Fraction& a, const Fraction& b)
{
	Fraction r;
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

Fraction operator *(const Fraction& a, const Fraction& b)
{
	Fraction r;
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

Fraction operator /(const Fraction& a, const Fraction& b)
{
	Fraction r;
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

bool operator ==(Fraction& a, Fraction& b)
{
	return a.toFloat() == b.toFloat();
}

bool operator !=(Fraction& a, Fraction& b)
{
	return a.toFloat() != b.toFloat();
}

bool operator >=(Fraction& a, Fraction& b)
{
	return a.toFloat() >= b.toFloat();
}

bool operator >(Fraction& a, Fraction& b)
{
	return a.toFloat() > b.toFloat();
}

bool operator <=(Fraction& a, Fraction& b)
{
	return a.toFloat() <= b.toFloat();
}

bool operator <(Fraction& a, Fraction& b)
{
	return a.toFloat() < b.toFloat();
}

string Fraction::DigitString::toString() const {
	stringstream sout;
	sout << GetNum();
	return sout.str();
};

void Fraction::DigitString::Init(string num)
{
	SetNum(num);
}

void Fraction::DigitString::Read()
{
	string num;
	cout << "	Number.exp = ? "; cin >> num;
	Init(num);
}

void Fraction::DigitString::Display()
{
	cout << toString();
}

Fraction::DigitString Add(const Fraction::DigitString& a, const Fraction::DigitString& b)
{
	Fraction::DigitString r;
	stringstream sout;
	sout << (a.toInt() + b.toInt());
	r.SetNum(sout.str());
	return r;
}

Fraction::DigitString Sub(const Fraction::DigitString& a, const Fraction::DigitString& b)
{
	Fraction::DigitString r;
	stringstream sout;
	sout << a.toInt() - b.toInt();
	r.SetNum(sout.str());
	return r;
}

Fraction::DigitString Mul(const Fraction::DigitString& a, const Fraction::DigitString& b)
{
	Fraction::DigitString r;
	stringstream sout;
	sout << a.toInt() * b.toInt();
	r.SetNum(sout.str());
	return r;
}

Fraction::DigitString Div(const Fraction::DigitString& a, const Fraction::DigitString& b)
{
	Fraction::DigitString r;
	stringstream sout;
	sout << a.toInt() / b.toInt();
	r.SetNum(sout.str());
	return r;
}

int Compare(const Fraction::DigitString& a, const Fraction::DigitString& b)
{
	if (a.toInt() < b.toInt())
		return 0;
	else if (a.toInt() > b.toInt())
		return 1;
	else
		return -1;
}

Fraction::DigitString& Fraction::DigitString::operator --() // префіксний декремент
{
	int v = toInt();
	--v;
	stringstream sout;
	sout << v;
	SetNum(sout.str());
	return *this; // повернули модифікований об'єкт
}

Fraction::DigitString& Fraction::DigitString::operator ++() // префіксний інкремент
{
	int v = toInt();
	++v;
	stringstream sout;
	sout << v;
	SetNum(sout.str());
	return *this; // повернули модифікований об'єкт
}

Fraction::DigitString Fraction::DigitString::operator --(int) // постфіксний декремент
{
	Fraction::DigitString a(*this); // створили копію
	int v = toInt();
	v--;
	stringstream sout;
	sout << v;
	SetNum(sout.str());
	return a; // повернули копію
}

Fraction::DigitString Fraction::DigitString::operator ++(int) // постфіксний інкремент
{
	Fraction::DigitString a(*this); // створили копію
	int v = toInt();
	v++;
	stringstream sout;
	sout << v;
	SetNum(sout.str());
	return a; // повернули копію
}

ostream& operator <<(ostream& out, const Fraction::DigitString& ds)
{
	return out << ds.toString();
}

istream& operator >>(istream& in, Fraction::DigitString& ds)
{
	string n;
	cout << ".exp ? = "; in >> n;
	ds.SetNum(n);
	//cout << endl;
	return in;
}

Fraction::DigitString& Fraction::DigitString::operator =(const Fraction::DigitString& ds)
{
	SetNum(ds.GetNum());
	return *this; // повернули посилання на поточний об’єкт
}

Fraction::DigitString::operator string() const
{
	return toString();
}

Fraction::DigitString operator +(const Fraction::DigitString& a, const Fraction::DigitString& b)
{
	Fraction::DigitString r;
	stringstream sout;
	sout << (a.toInt() + b.toInt());
	r.SetNum(sout.str());
	return r;
}

Fraction::DigitString operator -(const Fraction::DigitString& a, const Fraction::DigitString& b)
{
	Fraction::DigitString r;
	stringstream sout;
	sout << a.toInt() - b.toInt();
	r.SetNum(sout.str());
	return r;
}

Fraction::DigitString operator *(const Fraction::DigitString& a, const Fraction::DigitString& b)
{
	Fraction::DigitString r;
	stringstream sout;
	sout << a.toInt() * b.toInt();
	r.SetNum(sout.str());
	return r;
}

Fraction::DigitString operator /(const Fraction::DigitString& a, const Fraction::DigitString& b)
{
	Fraction::DigitString r;
	stringstream sout;
	sout << a.toInt() / b.toInt();
	r.SetNum(sout.str());
	return r;
}

bool operator ==(const Fraction::DigitString& a, const Fraction::DigitString& b)
{
	return a.toInt() == b.toInt();
	//return true;
	//return strcmp(a.toString().c_str(), b.toString().c_str()) > 0;
}

bool operator !=(const Fraction::DigitString& a, const Fraction::DigitString& b)
{
	return a.toInt() != b.toInt();
}

bool operator >=(const Fraction::DigitString& a, const Fraction::DigitString& b)
{
	return a.toInt() >= b.toInt();
}

bool operator >(const Fraction::DigitString& a, const Fraction::DigitString& b)
{
	return a.toInt() > b.toInt();
}

bool operator <=(const Fraction::DigitString& a, const Fraction::DigitString& b)
{
	return a.toInt() <= b.toInt();
}

bool operator <(const Fraction::DigitString& a, const Fraction::DigitString& b)
{
	return a.toInt() < b.toInt();
}
