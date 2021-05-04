// Source.cpp
//#include <iostream>
//#include "Triangle.h"
#include "Right.h"
#include "Equilateral.h"
#include "Isosceles.h"

//using namespace std;

int main()
{
    {
        Right r(10, 10, 90);
        cout << typeid(r).name() << endl;
        //cout << typeid(&r).name() << endl;
        r.Print();
        cout << "Square = " << r.Square() << endl << "Perimeter = " << r.Perimeter() << endl;

        Isosceles i(10, 10, 40);
        cout << typeid(i).name() << endl;
        //cout << typeid(&i).name() << endl;
        i.Print();
        cout << "Square = " << i.Square() << endl << "Perimeter = " << i.Perimeter() << endl;

        Equilateral e(10, 10, 60);
        cout << typeid(e).name() << endl;
        //cout << typeid(&e).name() << endl;
        e.Print();
        cout << "Square = " << e.Square() << endl << "Perimeter = " << e.Perimeter() << endl;

        cout << endl;
    }

    {
        Right* r = new Right(10, 10, 90);
        cout << typeid(*r).name() << endl;
        //cout << typeid(r).name() << endl;
        (*r).Print();
        cout << "Square = " << (*r).Square() << endl << "Perimeter = " << (*r).Perimeter() << endl;
        delete r;

        Isosceles* i = new Isosceles(10, 10, 40);
        cout << typeid(*i).name() << endl;
        //cout << typeid(i).name() << endl;
        (*i).Print();
        cout << "Square = " << (*i).Square() << endl << "Perimeter = " << (*i).Perimeter() << endl;
        delete i;

        Equilateral* e = new Equilateral(10, 10, 60);
        cout << typeid(*e).name() << endl;
        //cout << typeid(e).name() << endl;
        (*e).Print();
        cout << "Square = " << (*e).Square() << endl << "Perimeter = " << (*e).Perimeter() << endl;
        delete e;

        cout << endl;
    }

    {
        Triangle* b[3];

        b[0] = new Right(10, 10, 90);
        cout << "Currect object type : " << typeid(*b[0]).name() << endl;
        //cout << "Currect object type : " << typeid(*((Line*)b[0])).name() << endl;
        cout << "Base object type : " << typeid(b[0]).name() << endl;
        (*b[0]).Print();
        cout << "Square = " << (*b[0]).Square() << endl
            << "Perimeter = " << (*b[0]).Perimeter() << endl;

        b[1] = new Isosceles(10, 10, 40);
        cout << "Currect object type : " << typeid(*b[1]).name() << endl;
        //cout << "Currect object type : " << typeid(*((Line*)b[1])).name() << endl;
        cout << "Base object type : " << typeid(b[1]).name() << endl;
        (*b[1]).Print();
        cout << "Square = " << (*b[1]).Square() << endl
            << "Perimeter = " << (*b[1]).Perimeter() << endl;

        b[2] = new Equilateral(10, 10, 60);
        cout << "Currect object type : " << typeid(*b[2]).name() << endl;
        //cout << "Currect object type : " << typeid(*((Line*)b[2])).name() << endl;
        cout << "Base object type : " << typeid(b[2]).name() << endl;
        (*b[2]).Print();
        cout << "Square = " << (*b[2]).Square() << endl
            << "Perimeter = " << (*b[2]).Perimeter() << endl;

        for (int j = 0; j < 3; j++)
            delete b[j];

        cout << endl;
    }

    return 0;
}