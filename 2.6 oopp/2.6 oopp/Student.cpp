// Student.cpp
// файл реалізації – реалізація методів класу
#include "Student.h"
#include <iostream>
#include <sstream>

using namespace std;

void Student::Init(int course, Man man)
{
	SetCourse(course);
	SetMan(man);
}

string Student::toString() const
{
	stringstream sout;
	sout << "Course : " << GetCourse() << endl
		<< GetMan()
		;
	return sout.str();
}

void Student::Display() const
{
	cout << toString();
}

void Student::Read()
{
	int c;
	Man m;
	cout << endl;
	cout << "Man = ? " << endl;
	m.Read(); // використовуємо делегування
	cout << "course = ? "; cin >> c;
	Init(c, m);
}

Student::Student(const int course, const string name, const int age, const char gender, const double weight)
	: course(course), man(name, age, gender, weight)
{}

Student& Student::operator --() // префіксний декремент
{
	--course; // модифікували поточний об'єкт
	return *this; // повернули модифікований об'єкт
}

Student& Student::operator ++() // префіксний інкремент
{
	++course; // модифікували поточний об'єкт
	return *this; // повернули модифікований об'єкт
}

Student Student::operator --(int) // постфіксний декремент
{
	Student a(*this); // створили копію
	course--; // модифікували поточний об'єкт
	return a; // повернули копію
}

Student Student::operator ++(int) // постфіксний інкремент
{
	Student a(*this); // створили копію
	course++; // модифікували поточний об'єкт
	return a; // повернули копію
}

ostream& operator <<(ostream& out, const Student& s)
{
	return out << s.toString();
}

istream& operator >>(istream& in, Student& s)
{
	int course;
	Student::Man man;
	cout << "course = ? "; in >> course;
	s.SetCourse(course);
	cout << "man : " << endl; in >> man;
	s.SetMan(man);
	return in;
}

Student& Student::operator =(const Student& s)
{
	SetMan(s.GetMan());
	SetCourse(s.GetCourse());
	return *this; // повернули посилання на поточний об’єкт
}

Student::operator string() const
{
	stringstream sout;
	sout << toString();
	return sout.str();
}

void Student::Man::Init(string name, int age, char gender, double weight)
{
	SetName(name);
	SetAge(age);
	SetGender(gender);
	SetWeight(weight);
}

string Student::Man::toString() const
{
	stringstream sout;
	sout << "	Name : " << GetName() << endl
		<< "	Age : " << GetAge() << endl
		<< "	Gender : " << GetGender() << endl
		<< "	Weight : " << GetWeight()
		;
	return sout.str();
}

void Student::Man::Display() const
{
	cout << toString();
}

void Student::Man::Read()
{
	string name;
	int age;
	char gender;
	double weight;

	cout << endl;
	cout << "name = ? "; cin >> name;
	cout << "age = ? "; cin >> age;
	cout << "gender = ? "; cin >> gender;
	cout << "weight = ? "; cin >> weight;
	Init(name, age, gender, weight);
}

Student::Man& Student::Man::operator --() // префіксний декремент
{
	--age; // модифікували поточний об'єкт
	return *this; // повернули модифікований об'єкт
}

Student::Man& Student::Man::operator ++() // префіксний інкремент
{
	++age; // модифікували поточний об'єкт
	return *this; // повернули модифікований об'єкт
}

Student::Man Student::Man::operator --(int) // постфіксний декремент
{
	Man a(*this); // створили копію
	age--; // модифікували поточний об'єкт
	return a; // повернули копію
}

Student::Man Student::Man::operator ++(int) // постфіксний інкремент
{
	Man a(*this); // створили копію
	age++; // модифікували поточний об'єкт
	return a; // повернули копію
}

ostream& operator <<(ostream& out, const Student::Man& m)
{
	return out << "	Name : " << m.GetName() << endl
		<< "	Age : " << m.GetAge() << endl
		<< "	Gender : " << m.GetGender() << endl
		<< "	Weight : " << m.GetWeight();
}

istream& operator >>(istream& in, Student::Man& m)
{
	string name;
	int age;
	char gender;
	double weight;
	cout << "name = ? "; in >> name;
	m.SetName(name);
	cout << "age = ? "; in >> age;
	m.SetAge(age);
	cout << "gender = ? "; in >> gender;
	m.SetGender(gender);
	cout << "weight = ? "; in >> weight;
	m.SetWeight(weight);
	cout << endl;
	return in;
}

Student::Man& Student::Man::operator =(const Student::Man& m)
{
	SetName(m.GetName());
	SetAge(m.GetAge());
	SetGender(m.GetGender());
	SetWeight(m.GetWeight());
	return *this;
}

Student::Man::operator string() const
{
	stringstream sout;
	sout << toString();
	return sout.str();
}