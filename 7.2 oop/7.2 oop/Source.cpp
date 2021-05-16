// обчислити кількість від'ємних елементів 
// спосіб 2 - використання алгоритмів STL 
#include <iostream>     // std::cout 
#include <list>         // std::list 
#include <algorithm>    // std::generate 
#include <ctime>        // std::time 
#include <numeric>      // std::accumulate 
#include <functional>

using namespace std;

 int RandomNumber() { return rand() % 100 - 50; } 

void print(list<int> a)
{
    for (int i : a)         cout << i << " ";     cout << endl;
}  int main() {
    srand((unsigned int)time(NULL));     int n;
    cout << "n = ? "; cin >> n;     list<int> l(n);

    generate(l.begin(), l.end(), RandomNumber);     print(l);

    auto k = count_if(l.begin(), l.end(), [](int i) {return i < 0; });
    cout << "count of negative  = " << k << endl;

    return 0;
}
