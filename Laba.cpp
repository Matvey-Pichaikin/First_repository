#include <iostream>
#include <ctime>
using namespace std;
int main() {
srand(time(NULL));
const int n = 10;
int a[n];
int max;
int s = 1;
int j;
cout << "Изначальный массив"  << endl;
for (int i = 0; i < n; i++) {
a[i] = rand() % 100 - 50;
cout  << a[i]  << " ";
}
cout  << endl;
max = a[0];
for (int i = 0; i < n; i++) {
if (a[i] > max) {
max = a[i];
s = 1;
j = i;
}
else {
if (a[i] == max) {
s++;
}
}
}
cout  << "Макс "  << max  << endl;
cout  << "Номер "  << j+1  << endl;
cout  << "Кол-во "  << s  << endl;
}