#include <iostream>

using namespace std;

int fib(int n);

int main()
{
    int n = 15;

    for (int i = 0; i < n; i++)
    {
        cout << fib(i) << " ";
    }
    return 0;
}

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}