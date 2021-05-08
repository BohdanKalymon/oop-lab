// Student.h
#pragma once
#include <string>
//#include "Man.h"
//#pragma pack(push, 1)

using namespace std;

class Student
{
public:
	class Man
	{
	private:
		string name;
		int age;
		char gender;
		double weight;

	public:
		string GetName() const { return name; }
		int GetAge() const { return age; }
		char GetGender() const { return gender; }
		double GetWeight() const { return weight; }

		void SetName(string name) { this->name = name; }
		void SetAge(int age) { this->age = age; }
		void SetGender(char gender) { this->gender = gender; }
		void SetWeight(double weight) { this->weight = weight; }

		void Init(string name, int age, char gender, double weight);
		string toString() const;
		void Read();
		void Display() const;

		Man() { SetName(""); SetAge(0); SetGender('F'); SetWeight(0); }
		Man(string name) { SetName(name); SetAge(0); SetGender('F'); SetWeight(0); }
		Man(string name, int age) { SetName(name); SetAge(age); SetGender('F'); SetWeight(0); }
		Man(string name, int age, char gender) { SetName(name); SetAge(age); SetGender(gender); SetWeight(0); }
		Man(string name, int age, char gender, double weight) : name(name), age(age), gender(gender), weight(weight) { }
		Man(const Man& m) { SetName(m.GetName()); SetAge(m.GetAge()); SetGender(m.GetGender()); SetWeight(m.GetWeight()); }

		Man& operator --();
		Man& operator ++();
		Man operator --(int);
		Man operator ++(int);

		friend ostream& operator <<(ostream& out, const Man& m);
		friend istream& operator >>(istream& in, Man& m);

		Man& operator =(const Man& m);

		operator string() const;

	};


	int GetCourse() const { return course; }
	Man GetMan() const { return man; }

	void SetCourse(int course) { this->course = course; }
	void SetMan(Man man) { this->man = man; }

	void Init(int course, Man man);
	string toString() const;
	void Display() const;
	void Read();

	void IncCourse() { this->course++; }

	Student(const int course = 0, const string name = "Studentka", const int age = 0, const char gender = 'F', const double weight = 0);
	Student(const Student& s) { SetCourse(s.GetCourse()); SetMan(s.GetMan()); }

	Student& operator --();
	Student& operator ++();
	Student operator --(int);
	Student operator ++(int);

	friend ostream& operator <<(ostream& out, const Student& s);
	friend istream& operator >>(istream& in, Student& s);

	Student& operator =(const Student& s);

	operator string() const;

private:
	int course;
	Man man;


};