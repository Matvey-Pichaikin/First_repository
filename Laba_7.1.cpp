#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int m = 7;
const int n = 5;
const int x = 15;
const int nech = (m + 1) / 2;
int s = 0;
void delet(int arr[][n], int size, int newArr[][n]);
void delet(int arr[], int size);
int main()
{
    srand(time(0));

    int a[m][n];
    int b[nech][n];

    int c[x] = {1, 4, -6, 0, 2, 8, 5, -3, 1, 4, 7, 0, 2, 5, 7};
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 201 - 100;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    delet(a, m, b);
    cout << endl << endl;
    for (int i = 0; i < x; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
    delet(c, x);
    return 0;
}

void delet(int arr[][n], int size, int newArr[][n]) 
{
    for (int i = 0; i < size; i += 2)  
    {
        
        for (int j = 0; j < n; j++) 
        {
            newArr[i][j] = arr[i][j];  
            cout << newArr[i][j] << " ";
        }
        cout << endl;
    } 
}
    
void delet(int arr[], int size) 
{
    bool First_zero_found = false;
    for (int i = 0; i < size; i ++)
    {
        if (arr[i] == 0) 
        {
            if (First_zero_found)
            {
                First_zero_found = false;
                cout << arr[i] << " ";
            }
            else
            {
                cout << arr[i] << " ";
                First_zero_found = true;
            }
        }
        else 
        {
            if (arr[i] != 0 && First_zero_found)
                continue; 
            else
                cout << arr[i] << " ";  
        } 
    }
}
    
