#include <iostream>
#include <cmath>
using namespace std;

// Функция для вычисления расстояния между двумя точками
double distance(int x1, int y1, int x2, int y2) 
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Функция для вычисления площади треугольника по длинам его сторон
double triangleArea(double a, double b, double c) 
{
    double p = (a + b + c) / 2;  // Полупериметр
    return sqrt(p * (p - a) * (p - b) * (p - c));  // Формула Герона
}

// Функция для вычисления площади треугольника по координатам его вершин
double triangleAreaByCoords(int x1, int y1, int x2, int y2, int x3, int y3) 
{
    double a = distance(x1, y1, x2, y2);  // Длины сторон треугольника
    double b = distance(x2, y2, x3, y3);
    double c = distance(x3, y3, x1, y1);
    return triangleArea(a, b, c);  // Используем ранее созданную функцию для вычисления площади
}

// Функция для вычисления площади треугольника с помощью формулы Герона для любого количества вершин
double triangleArea(int n, int x[], int y[]) 
{
    double maxArea = 0.0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            for (int k = j + 1; k < n; k++) 
            {
                double area = triangleAreaByCoords(x[i], y[i], x[j], y[j], x[k], y[k]);
                if (area > maxArea) 
                {
                    maxArea = area;
                }
            }
        }
    }
    return maxArea;
}

int main() {
    cout << "Side length between points (1, 1) end (4, 5) =  " << distance(1, 1, 4, 5) << endl;

    cout << "Area of a triangle with sides of length 3, 4 end 5 = " << triangleArea(3, 4, 5) << endl;

    int x[] = {1, 3, 6, 1};
    int y[] = {1, 5, 1, 1};
    cout << "Area of a triangle containing the longest diagonal of the polygon = " << triangleArea(4, x, y) << endl;

    return 0;
}