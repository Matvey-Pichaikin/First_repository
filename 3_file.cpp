#include <iostream>
using namespace std;

float square(float number); 

int main(void)
{
    float number;
    cout << endl << "Введите число квадрат которого вы хотите получить: ";
    cin >> number;
    float new_number = square(number);
    cout << "Квадрат числа " << number << " = " << new_number <<endl;
    return 0;
}
float square(float number)
{
    return number * number;
}