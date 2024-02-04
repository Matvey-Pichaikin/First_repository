#include <iostream>
#include <ctime>

using namespace std;

const int n = 20;

int main() 
{
    int a[n];
    int k = 4;
    int temp;

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 101 - 50;
        cout << a[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < k; i++)
    {
        temp = a[0]; 
        for (int j = 0; j < n - 1; j++)
        {
         a[j] = a[j + 1]; 
        }
        a[n - 1] = temp; 
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}