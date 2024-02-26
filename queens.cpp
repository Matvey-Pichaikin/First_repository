#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Solve_Queens(int queens[], int row);
bool Is_Safe(const int queens[], int row, int col);
void Print_Solution(const int queens[]);


int main() 
{
    int queens[8] = {0};
    Solve_Queens(queens, 0);
    return 0;
}


void Solve_Queens(int queens[], int row) 
{
    if (row == 8) 
    {
        Print_Solution(queens);
        return;
    }
    
    for(int col = 0; col < 8; ++col) 
    {
        if (Is_Safe(queens, row, col)) 
        {
            queens[row] = col;
            Solve_Queens(queens, row + 1);
        }
    }
}


bool Is_Safe(const int queens[], int row, int col) 
{
    for(int i = 0; i < row; ++i) 
    {
        if(queens[i] == col || queens[i] - col == i - row || queens[i] - col == row - i) 
        {
            return false;
        }
    }
    return true;
}


void Print_Solution(const int queens[]) 
{
    static int Solution_Num = 1;
    string  File_Name = "Solution_";

    if (Solution_Num < 10) 
        File_Name += Solution_Num + 48;
    else 
    {
        File_Name += Solution_Num / 10 + 48;
        File_Name += Solution_Num % 10 + 48;
    }

    ofstream File;
    File.open(File_Name);
    
    for(int i = 0; i < 8; ++i) 
    {
        for(int j = 0; j < 8; ++j) 
        {
            if(queens[i] == j) 
            {
                File << "Q ";
            } 
            else 
            {
                File << ". ";
            }
        }
        File << endl;
    }
    
    ++Solution_Num;
    File.close();
}