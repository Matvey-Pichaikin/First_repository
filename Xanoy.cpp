#include <iostream>
using namespace std;
int s = 1;
void Xanoy(int n, char start, char end, char temp);

int main()
{
    system("chcp 65001");
    system("cls");
    int n = 3;
    Xanoy(n, 'A', 'C', 'B'); 
    return 0;
}

void Xanoy(int n, char start, char end, char temp) 
{
    cout << "-> Enter Xanoy(" << n << ")\n";
    if (n == 1) 
    {
        cout << s << ". Move disk 1 from " << start << " to " << end << endl;
        cout << "<- Leaving Xanoy(" << n << ")\n";
        s++;
        return;
    }
    Xanoy(n - 1, start, temp, end);;
    cout << s << ". Move disk " << n << " from " << start << " to "  << end << endl;
    s++;
    Xanoy(n - 1, temp, end, start);
}