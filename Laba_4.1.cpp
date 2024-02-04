#include <iostream>
#include <ctime> 
#include <cmath>

using namespace std;

const int n = 8; 
const int k = 4; 

int main()
{
    srand(time(NULL));
    int a[n];
    int number = 0; 

    for (int i = 0; i < n; i++) 
    {
        a[i] = rand() % 101 - 50;
        cout << a[i] << " ";
        if (abs(a[i]) % 2 == 1)
            number++; 
    }
    cout << endl;

    for (int i = k; i <= k + 1; i++) 
    {
        cout << a[i % n] << " ";
    }

    cout << endl;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (a[j] > a[j + 1]) 
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) 
    {
        cout << a[i] << " ";
    }
    cout << endl;

    int b[n - number]; 

    int i, j = 0;

    for (i = 0; i < n; i++) 
    {
        if (a[i] % 2 == 0) 
        {
            b[j] = a[i];
            j++;
        }
    }

    for (int i = 0; i < n - number; i++) 
    {
        cout << b[i] << " ";
    }
    cout << endl;

    
    for (int i = k; i <= k + 1; i++) 
    {
        cout << b[i % (n - number)] << " ";
    }
    return 0;
}




