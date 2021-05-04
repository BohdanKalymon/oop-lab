// Fraction.h
#pragma once
#include "DigitString.h"
//#pragma pack(push, 1)

using namespace std;

class Fraction
	: public DigitString
{
private:
	//DigitString exp;
	unsigned int frac;

public:
	DigitString GetExp() const
	{
		return this->GetNum();
	}

	void SetExp(DigitString exp)
	{
		this->SetNum(exp.GetNum());
	}

	unsigned GetFrac() const { return frac; }
	void SetFrac(unsigned int val) { frac = val; }

	string toString() const;
	float toFloat() const;

	void Init(string exp, unsigned int frac);
	void Read();
	void Display();

	friend Fraction Add(const Fraction& a, const Fraction& b);
	friend Fraction Sub(const Fraction& a, const Fraction& b);
	friend Fraction Mul(const Fraction& a, const Fraction& b);
	friend Fraction Div(const Fraction& a, const Fraction& b);
	friend int Compare(const Fraction& a, const Fraction& b);

	Fraction(const string num = "0", const unsigned int frac = 0) throw(const char*, Exception, Bad_exception)
	{
		if (frac == 100)
			throw Exception("My Custom Exception");
		else if (frac == 101)
			throw Bad_exception("My Derived Exception");
		else if (frac == 102)
			throw invalid_argument("invalid_agrument");
		else if (frac == 103)
			throw bad_exception();
		this->SetNum(num);
		SetFrac(frac);
	}
	Fraction(const Fraction& f) { Init(f.GetNum(), f.frac); }

	Fraction& operator --();
	Fraction& operator ++();
	Fraction operator --(int);
	Fraction operator ++(int);

	friend ostream& operator <<(ostream& out, const Fraction& f);
	friend istream& operator >>(istream& in, Fraction& f) throw(const char*);

	Fraction& operator =(const Fraction& f);

	operator string() const;

	friend Fraction operator +(const Fraction& a, const Fraction& b);
	friend Fraction operator -(const Fraction& a, const Fraction& b);
	friend Fraction operator *(const Fraction& a, const Fraction& b);
	friend Fraction operator /(const Fraction& a, const Fraction& b);

	friend bool operator ==(Fraction a, Fraction& b);
	friend bool operator !=(Fraction a, Fraction& b);
	friend bool operator >=(Fraction a, Fraction& b);
	friend bool operator >(Fraction a, Fraction& b);
	friend bool operator <=(Fraction a, Fraction& b);
	friend bool operator <(Fraction a, Fraction& b);

};