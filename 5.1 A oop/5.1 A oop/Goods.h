// Goods.h

#pragma once
//#pragma pack(push, 1)
//#pragma pack(1)
#include <string>
#include "Exception.h"
#include "Bad_exception.h"

#include <exception>;
#include <stdexcept>;

using namespace std;

class Goods
{
private:
	double first;
	int second;

public:
	double GetFirst() const;
	int GetSecond() const;
	bool SetFirst(double value);
	bool SetSecond(int value);

	bool Init(double first, int second);
	void Read();
	void Display();

	Goods(double first = 0, int second = 0) throw(const char*, Exception, Bad_exception, bad_exception&, invalid_argument&)
	{
		if (first < 0 && second < 0)
			throw Exception("My Custom Exception");
		else if (first < 0)
			throw Bad_exception("My Derived Exception");
		else if (second < 0)
			throw invalid_argument("invalid_agrument");
		else if (second == 1000000)
			throw bad_exception();
		SetFirst(first);
		SetSecond(second);
	}

	Goods(const Goods& g) { SetFirst(g.first); SetSecond(g.second); }

	double cost();

	Goods& operator --();
	Goods& operator ++();
	Goods operator --(int);
	Goods operator ++(int);

	friend ostream& operator <<(ostream& out, const Goods& g);
	friend istream& operator >>(istream& in, Goods& g) throw(const char*, bad_exception&);

	Goods& operator =(const Goods& g);

	operator string() const;

	string toString() const;


};
