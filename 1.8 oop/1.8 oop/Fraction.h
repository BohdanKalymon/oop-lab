// Fraction.h
#pragma once
#include <string>

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

		void Init(string num);
		void Read();
		void Display();

		string toString() const;
		int toInt() const { return atoi(GetNum().c_str()); };

		friend DigitString Add(const DigitString& a, const DigitString& b);
		friend DigitString Sub(const DigitString& a, const DigitString& b);
		friend DigitString Mul(const DigitString& a, const DigitString& b);
		friend DigitString Div(const DigitString& a, const DigitString& b);
		friend int Compare(const DigitString& a, const DigitString& b);

	};


	Fraction::DigitString GetExp() const { return exp; }
	void SetExp(Fraction::DigitString val) { exp = val; }
	unsigned GetFrac() const { return frac; }
	void SetFrac(unsigned int val) { frac = val; }

	void Init(string exp, unsigned int frac);
	void Read();
	void Display();

	string toString() const;
	float toFloat() const;

	friend Fraction Add(const Fraction& a, const Fraction& b);
	friend Fraction Sub(const Fraction& a, const Fraction& b);
	friend Fraction Mul(const Fraction& a, const Fraction& b);
	friend Fraction Div(const Fraction& a, const Fraction& b);
	friend int Compare(const Fraction& a, const Fraction& b);

private:
	DigitString exp;
	unsigned int frac;

};