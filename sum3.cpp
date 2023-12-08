#include <iostream>
using namespace std;


int main()
{
    double s = 0, x, u = 1;
    int i = 1, n;
    
    
    setlocale(LC_ALL, "ru");
    cout << "Введите количество элементов: ";
    cin >> n;
    cout << "Введите x: ";
    cin >> x;

    while (i <= n)
    {
        s = s + u;
        u = u * x / i;
        i += 1;
    }
    cout <<"Сумма элементов: "<< s;
}