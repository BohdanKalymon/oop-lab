// побудувати множину символів A-F,  
// які є хоча б в одному із двох введених літерних рядків 
// спосіб 2 - використання алгоритмів STL 
#include <iostream> 
#include <sstream> 
#include <string> 
#include <set> 
#include <algorithm> 
#include <Windows.h>  

using namespace std;

void print(set<char> s)
{
    stringstream ss;     ss << "{";     for (auto i : s)         ss << i << ";";

    string st = ss.str();
    st = st.erase(st.length() - 1) + "}";     cout << st << endl;
}

set<char> difference(set<char> a, set<char> b)
{
    set<char> r(a);  // r = a    
    for (auto v : b) 
    r.erase(v);  // r = a - b   
    return r; 
}

// використання операцй над множинами 
set<char> calc(set<char> s1, set<char> s2, set<char> s0)
{
    set<char> s = difference(s0, s1); // s = s0 - s1    
    s = difference (s, s2);            // s = s - s2     // отримали: символи базової, які не входять в s1 та s2 
    // s = s0 - s1 - s2 
    set<char> r = difference(s0, s);  // r = s0 - s     // отримали: символи базової, які входять в s1 або в s2 
   // r = s0 - (s0 - s1 - s2) 
   // r = s0 * (s1 + s2) 

    return r;
}
int count(set<char> s)
{
    return  std::count(s.begin(), s.end(), 'a');
}  int main()
{
    // забезпечення відображення кирилиці: 
    SetConsoleCP(1251);          // встановлення кодової сторінки win-cp1251                                
                                 // (кирилиця) в потік вводу 
    SetConsoleOutputCP(1251);    // встановлення кодової сторінки win-cp1251 
                                 // (кирилиця) в потік виводу 

    string t1;                                // вводимо 1-й літерний рядок   
    cout << "перша послідовність символів: "; getline(cin, t1); 
    set<char> s1(t1.begin(), t1.end());       // перша множина    
    cout << "перша множина: " << endl; print(s1); 
    string t2;                                // вводимо 2-й літерний рядок   
    cout << "друга послідовність символів: "; getline(cin, t2); 

    set<char> s2(t2.begin(), t2.end());       // друга множина   
    cout << "друга множина: " << endl; print(s2); 
    string t0 = "ABCDEF";                     // базова множина 
    set<char> s0(t0.begin(), t0.end()); 
    cout << "базова множина: " << endl; print(s0);

    set<char> s;                              // результуюча множина   
    s = calc(s1, s2, s0); 
    cout << "результуюча множина: " << endl; print(s);

    return 0;
}
