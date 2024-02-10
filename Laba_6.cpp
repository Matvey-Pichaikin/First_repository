#include <iostream>
#include <cmath>

int factorial(int n);
double function(double x, int n);
double sum(double x, int n);
double sum_2(double x, int n);

int main()
{
    int n = 2;
    double x = 1.0;
    std::cout << sum(x, n) << std::endl;
    std::cout << sum_2(x, n);
    return 0;
}

int factorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * factorial(n-1);
}

double function(double x, int n)
{
    return pow(x, 2*n+1) / factorial(2*n+1);
}

double sum(double x, int n)  // через рекурсию
{
    if (n == 0)
        return x;
    else    
        return sum(x, n-1) + function(x, n);
}

double sum_2(double x, int n) // через цикл в функции
{
    double result = 0; 
    for (int i = 0; i <= n; i++) {
        result += function(x, i);
    }
    return result;
}