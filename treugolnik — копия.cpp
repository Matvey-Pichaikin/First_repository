#include <iostream>
using namespace std;

int main() 
{
	setlocale(LC_ALL, "Rus");
	int N;
	cin >> N;
	while ((N <= 3) || (N % 2 == 0)) 
    {
		cout << "Ошибка. Введите нечётное N > 3";	
		cin >> N;
    }
	int p = (N - 1) / 2;
	int z = 1;
	cout << endl;

	for (int i = 1; i <= (N + 1) / 2; i++) {
		for (int j =1; j <=p; j++)
		{
			cout << " ";
		}
		p = p - 1;
		for (int j = 1; j <= z; j++)
		{
			cout << "*";
		}
		z = z + 2;
		cout << endl;
	}
	return 0;
}
