// Fraction.h
#pragma once
//#include "DigitString.h"
#include <string>
//#pragma pack(push, 1)

using namespace std;

class Fraction
{
public:
	class DigitString
	{
	private:
		string num;

	public:
		string GetNum() const { return num; };
		void SetNum(string val) { num = val; };

		string toString() const;
		int toInt() const { return atoi(GetNum().c_str()); };

		void Init(string num);
		void Read();
		void Display();

		friend DigitString Add(const DigitString& a, const DigitString& b);
		friend DigitString Sub(const DigitString& a, const DigitString& b);
		friend DigitString Mul(const DigitString& a, const DigitString& b);
		friend DigitString Div(const DigitString& a, const DigitString& b);
		friend int Compare(const DigitString& a, const DigitString& b);

		DigitString() { SetNum(""); }
		DigitString(string num) { SetNum(num); }
		DigitString(const DigitString& ds) { SetNum(ds.num); }

		DigitString& operator --();
		DigitString& operator ++();
		DigitString operator --(int);
		DigitString operator ++(int);

		friend ostream& operator <<(ostream& out, const DigitString& ds);
		friend istream& operator >>(istream& in, DigitString& ds);

		DigitString& operator =(const DigitString& ds);

		operator string() const;

		friend DigitString operator +(const DigitString& a, const DigitString& b);
		friend DigitString operator -(const DigitString& a, const DigitString& b);
		friend DigitString operator *(const DigitString& a, const DigitString& b);
		friend DigitString operator /(const DigitString& a, const DigitString& b);

		friend bool operator ==(const DigitString& a, const DigitString& b);
		friend bool operator !=(const DigitString& a, const DigitString& b);
		friend bool operator >=(const DigitString& a, const DigitString& b);
		friend bool operator <=(const DigitString& a, const DigitString& b);
		friend bool operator >(const DigitString& a, const DigitString& b);
		friend bool operator <(const DigitString& a, const DigitString& b);

	};

	Fraction::DigitString GetExp() const { return exp; }
	void SetExp(Fraction::DigitString val) { exp = val; }
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

	//Fraction() { const string num = ""; SetFrac(0); }
	Fraction(const string num = "0", const unsigned int frac = 0) : exp(num), frac(frac) {}
	Fraction(const Fraction& f) { SetExp(f.exp); SetFrac(f.frac); }

	Fraction& operator --();
	Fraction& operator ++();
	Fraction operator --(int);
	Fraction operator ++(int);

	friend ostream& operator <<(ostream& out, const Fraction& f);
	friend istream& operator >>(istream& in, Fraction& f);

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


private:
	DigitString exp;
	unsigned int frac;

};
