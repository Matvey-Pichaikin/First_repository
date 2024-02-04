#include <iostream>
#include <ctime>

using namespace std;

const int n = 20;

int main() 
{
    int a[n];
    int p = 4;
    int q = 15;
    int temp;

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 101 - 50;
        cout << a[i] << " ";
    }
    cout << endl;
    while (p < q)
    {
        temp = a[p];
        a[p] = a[q];
        a[q] = temp;
        p++;
        q--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}