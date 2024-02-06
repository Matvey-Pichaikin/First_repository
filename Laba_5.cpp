#include <iostream>
#include <ctime>
using namespace std;
const int n = 3;
int main() 
{
    int a[n][n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 101 - 50;
            cout << a[i][j] << "  ";
        }
       cout << endl;
    }
    cout << endl;

    for (int k = 0; k < n; k++) 
    {
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] > a[k][k])
                {
                    s++;
                }    
            }
        }
        cout << "Количество элементов > " << a[k][k] << "  - " << s  << endl;
    }
    return 0;
}