// Source.cpp
#include "Right.h"
#include "Equilateral.h"
#include "Isosceles.h"

ostream& operator << (ostream& out, const Triangle& v) { return v.Print(out); }
istream& operator >> (istream& in, Triangle& v) { return v.Input(in); }

int main()
{

    Right* r0 = new Right();
    cin >> *r0;
    cout << typeid(*r0).name() << endl;
    (*r0).Print();
    cout << "*r0 : " << *r0 << endl;
    cout << "r0: Square = " << (*r0).Square() << endl << "Perimeter = " << (*r0).Perimeter() << endl;


    Right r(10, 10, 90);
    cout << typeid(r).name() << endl;
    //cout << typeid(&r).name() << endl;
    r.Print();
    cout << "r: Square = " << r.Square() << endl << "Perimeter = " << r.Perimeter() << endl;

    Isosceles i(10, 10, 40);
    cout << typeid(i).name() << endl;
    //cout << typeid(&i).name() << endl;
    i.Print();
    cout << "i: Square = " << i.Square() << endl << "Perimeter = " << i.Perimeter() << endl;

    Equilateral e(10, 10, 60);
    cout << typeid(e).name() << endl;
    //cout << typeid(&e).name() << endl;
    e.Print();
    cout << "e: Square = " << e.Square() << endl << "Perimeter = " << e.Perimeter() << endl;

    cout << endl;


    Right* r2 = new Right(10, 10, 90);
    cout << typeid(*r2).name() << endl;
    //cout << typeid(r2).name() << endl;
    (*r2).Print();
    cout << "*r2: Square = " << (*r2).Square() << endl << "Perimeter = " << (*r2).Perimeter() << endl;

    Isosceles* i2 = new Isosceles(10, 10, 40);
    cout << typeid(*i2).name() << endl;
    //cout << typeid(i2).name() << endl;
    (*i2).Print();
    cout << "*i2: Square = " << (*i2).Square() << endl << "Perimeter = " << (*i2).Perimeter() << endl;

    Equilateral* e2 = new Equilateral(10, 10, 60);
    cout << typeid(*e2).name() << endl;
    //cout << typeid(e2).name() << endl;
    (*e2).Print();
    cout << "*e2: Square = " << (*e2).Square() << endl << "Perimeter = " << (*e2).Perimeter() << endl;

    cout << endl;


    Triangle* b[5];


    //
    b[0] = new Right(10, 10, 90);
    cout << "Currect object type : " << typeid(*b[0]).name() << endl;
    //cout << "Currect object type : " << typeid(*((Line*)b[0])).name() << endl;
    cout << "Base object type : " << typeid(b[0]).name() << endl;
    (*b[0]).Print();
    cout << "*b[0]: Square = " << (*b[0]).Square() << endl
        << "Perimeter = " << (*b[0]).Perimeter() << endl;

    b[1] = new Isosceles(10, 10, 40);
    cout << "Currect object type : " << typeid(*b[1]).name() << endl;
    //cout << "Currect object type : " << typeid(*((Line*)b[1])).name() << endl;
    cout << "Base object type : " << typeid(b[1]).name() << endl;
    (*b[1]).Print();
    cout << "*b[1]: Square = " << (*b[1]).Square() << endl
        << "Perimeter = " << (*b[1]).Perimeter() << endl;

    b[2] = new Equilateral(10, 10, 60);
    cout << "Currect object type : " << typeid(*b[2]).name() << endl;
    //cout << "Currect object type : " << typeid(*((Line*)b[2])).name() << endl;
    cout << "Base object type : " << typeid(b[2]).name() << endl;
    (*b[2]).Print();
    cout << "*b[2]: Square = " << (*b[2]).Square() << endl
        << "Perimeter = " << (*b[2]).Perimeter() << endl;

    cout << endl;

    //Right r(10, 10, 90);
    b[3] = &r;
    cout << "Currect object type : " << typeid(*b[3]).name() << endl;
    //cout << "Currect object type : " << typeid(*((Line*)b[3])).name() << endl;
    cout << "Base object type : " << typeid(b[3]).name() << endl;
    (*b[3]).Print();
    cout << "*b[3]: Square = " << (*b[3]).Square() << endl
        << "Perimeter = " << (*b[3]).Perimeter() << endl;

    cout << endl;

    //Right* r2 = new Right(10, 10, 90);
    b[4] = r2;
    cout << "Currect object type : " << typeid(*b[4]).name() << endl;
    //cout << "Currect object type : " << typeid(*((Line*)b[4])).name() << endl;
    cout << "Base object type : " << typeid(b[4]).name() << endl;
    (*b[4]).Print();
    cout << "*b[4]: Square = " << (*b[4]).Square() << endl
        << "Perimeter = " << (*b[4]).Perimeter() << endl;

    cout << endl;


    for (int i = 0; i < 3; i++)
    {
        delete b[i];
    }
    delete e2;
    delete i2;
    delete r2;


    return 0;
}