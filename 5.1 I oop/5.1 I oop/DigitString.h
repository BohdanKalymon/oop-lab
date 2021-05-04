//////////////////////////////////////////////////////////////////////////////
// DigitString.h
#pragma once
#include <string>
//#pragma pack(push, 1)
#include "Object.h"

#include "Exception.h"
#include "Bad_exception.h"

#include <exception>;
#include <stdexcept>;

using namespace std;

class DigitString
	: public Object
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
