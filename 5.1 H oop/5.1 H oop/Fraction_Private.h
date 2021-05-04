// Fraction_Private.h
#pragma once
#include "DigitString.h"
//#pragma pack(push, 1)

using namespace std;

class Fraction_Private
	: private DigitString
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

	friend Fraction_Private Add(const Fraction_Private& a, const Fraction_Private& b);
	friend Fraction_Private Sub(const Fraction_Private& a, const Fraction_Private& b);
	friend Fraction_Private Mul(const Fraction_Private& a, const Fraction_Private& b);
	friend Fraction_Private Div(const Fraction_Private& a, const Fraction_Private& b);
	friend int Compare(const Fraction_Private& a, const Fraction_Private& b);

	Fraction_Private(const string num = "0", const unsigned int frac = 0) throw(const char*, Exception, Bad_exception)
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
	Fraction_Private(const Fraction_Private& f) { Init(f.GetNum(), f.frac); }

	Fraction_Private& operator --();
	Fraction_Private& operator ++();
	Fraction_Private operator --(int);
	Fraction_Private operator ++(int);

	friend ostream& operator <<(ostream& out, const Fraction_Private& f);
	friend istream& operator >>(istream& in, Fraction_Private& f) throw(const char*);

	Fraction_Private& operator =(const Fraction_Private& f);

	operator string() const;

	friend Fraction_Private operator +(const Fraction_Private& a, const Fraction_Private& b);
	friend Fraction_Private operator -(const Fraction_Private& a, const Fraction_Private& b);
	friend Fraction_Private operator *(const Fraction_Private& a, const Fraction_Private& b);
	friend Fraction_Private operator /(const Fraction_Private& a, const Fraction_Private& b);

	friend bool operator ==(Fraction_Private a, Fraction_Private& b);
	friend bool operator !=(Fraction_Private a, Fraction_Private& b);
	friend bool operator >=(Fraction_Private a, Fraction_Private& b);
	friend bool operator >(Fraction_Private a, Fraction_Private& b);
	friend bool operator <=(Fraction_Private a, Fraction_Private& b);
	friend bool operator <(Fraction_Private a, Fraction_Private& b);

};
