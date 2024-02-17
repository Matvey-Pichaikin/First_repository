#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main() 
{
    cout << "Введите текст: ";
    string text;
    getline(cin, text);
    int num_points = text.size();
    for (int i = 0; i < num_points; ++i) 
    {
        double x = i * 5 * M_PI / num_points;
        double y = sin(x);
        int num_spaces = static_cast<int>((1 + y) * 20);
        for (int j = 0; j < num_spaces; ++j) 
        {
            std::cout << "  ";
        }
        std::cout << text[i] << "\n";
    }
    return 0;
}