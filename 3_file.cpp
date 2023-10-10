#include <iostream>
using namespace std;

float get_new_number(float, int); 

int main(void)
{
    float number;
    cout << endl << "Введите число которое вы хотите возвести в степень: ";
    cin >> number;
    int degree;
    cout << "Введите натуральную степень, в которую вы хотите возвести число: ";
    cin >> degree;
    float new_number = get_new_number(number, degree);
    cout << "Число " << number << " в степени " << degree << " = " << new_number <<endl;
    return 0;
}

float get_new_number(float number, int degree)
{
    int number_1 = number;
    for (int i = 1; i < degree; i++)
    {
        number = number * number_1;
    }
    return number;
}