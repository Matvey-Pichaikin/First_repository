#include <iostream>
using namespace std;
const int Size = 25;

int main()
{
    int arr[Size];
    int N;
    bool flag = true; // будем считать, что массив изначально упорядочен
    cout << "Введите N: ";
    cin >> N;

    while (N <= 1 || N > Size)
    {
        cout << "Введите N (от 0 до 25): ";
        cin >> N;
    }

    for (int i = 0; i < N; i++)
    {
        cout << "Введите " << i + 1 << " элемент: ";
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << ' ';
    }

    for (int i = 0; (i < (N - 1)) && (flag == true); i++)
    {
        if (arr[i] >= arr[i + 1])
            flag = false; 
    }

    if (flag)
        cout << "\nМассив упорядочен";
    else
        cout << "\nМассив не упорядочен";
    return 0;
}