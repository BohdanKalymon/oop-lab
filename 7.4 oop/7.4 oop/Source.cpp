#include <iostream> 
#include <string> 
#include <map> 
#include <ctime> 
#include <Windows.h>  // підключаємо бібліотеку, яка забезпечує відображення кирилиці 

using namespace std;

struct Train
{
    string city;   
    int type;   
    int hour;   
    int minute;
};
void add(map<int, Train>& c)
{
    int pos = c.size();
    int tmp2;     Train tmp;
    cout << "Місто відправлення : ";    
    cin >> tmp.city;

    cout << "[1] Звичайний" << endl;  
    cout << "[2] Підвищеного комфорту" << endl; 
    cout << "[3] Швидкісний експрес" << endl;    
    do {
        cin >> tmp2;
    } while (tmp2 < 1 || tmp2 > 3);  
    tmp.type = tmp2;

    cout << "Година відправлення : ";   
    do {
        cin >> tmp2;
    } while (tmp2 < 0 || tmp2 > 23);  
    tmp.hour = tmp2;

    cout << "Хвилина відправлення : ";   
    do {
        cin >> tmp2;
    } while (tmp2 < 0 || tmp2 > 59);  
    tmp.minute = tmp2;

    c.insert({ pos, tmp });
}
void display(map<int, Train> c)
{
    for (int i = 0; i < c.size(); i++)
    {
        cout << "Місто відправлення : " << c[i].city << endl;      
        if (c[i].type == 1)
            cout << "Тип      : Звичайний" << endl;     
        else
            if (c[i].type == 2)
                cout << "Тип      : Підвищеного комфорту" << endl;   
            else
                cout << "Тип      : Швидкісний експрес" << endl;
        cout << "Година відправлення  : " << c[i].hour << endl;      
        cout << "Хвилина відправлення : " << c[i].minute << endl;
    }
}  void display(map<int, Train> c, int j)
{
    for (int i = j; i < c.size(); i++)
    {
        cout << "Місто відправлення   : " << c[i].city << endl;    
        if (c[i].type == 1)
            cout << "Тип      : Звичайний" << endl; 
        else
            if (c[i].type == 2)
                cout << "Тип      : Підвищеного комфорту" << endl; 
            else
                cout << "Тип      : Швидкісний експрес" << endl;    
        cout << "Година відправлення  : " << c[i].hour << endl;      
        cout << "Хвилина відправлення : " << c[i].minute << endl;
    }
}
void display(map<int, Train> c, int h, int m)
{
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i].hour > h || (c[i].hour == h && c[i].minute > m))
        {
            display(c, i);         
            return;
        }
    }
}
void sort(map<int, Train>& c)
{
    for (int i = 0; i < c.size() - 1; i++)  
        for (int j = i; j < c.size(); j++)
    {
        if (c[i].hour > c[j].hour ||
            (c[i].hour == c[j].hour && c[i].minute > c[j].minute))
        {
            Train tmp;             
            tmp = c[i];        
            c.erase(i);
            c.insert({ i, c[j] });
            c.erase(j);
            c.insert({ j, tmp });
        }
    }
}  int main()
{
    // забезпечення кирилиці
    SetConsoleCP(1251);          
                                
    SetConsoleOutputCP(1251);   
                               
    map<int, Train> rozklad;

    int tmp2, tmp3, tmp4;     do {
        cout << "[1] Додати запис" << endl;   
        cout << "[2] Відобразити записи" << endl;  
        cout << "[3] Вивести відповідно до часу" << endl;      
        cout << "[0] Вийти" << endl;     
        do {
            cin >> tmp2;
        } while (tmp2 < 0 || tmp2 > 3);

        switch (tmp2)
        {
        case 1:
            add(rozklad);             sort(rozklad);    
            break;
        case 2:             display(rozklad);        
        break;         case 3:        
            cout << "Година відправлення : ";     
            do {
            cin >> tmp3;
        } while (tmp3 < 0 || tmp3 > 23);

        cout << "Хвилина відправлення : ";   
        do {
            cin >> tmp4;
        } while (tmp4 < 0 || tmp4 > 59);

        display(rozklad, tmp3, tmp4);        
        break;      
        default:       
            break;
        }

    } while (tmp2 != 0);

    return 0;
}
