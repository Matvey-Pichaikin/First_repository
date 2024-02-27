#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct student
{
    string surname;
    string name;
    string patronymic;
    string date_of_birth;
    string adress;
    float rating;
    bool is_repeat;
};

int main()
{
    system("chcp 65001");
    system("cls");

    int n;
    int repeat = 0;
    int surname_index;
    bool is_found = false; 
    string surname;

    ofstream File;
    File.open("Students.txt");

    if (!File.is_open())
        exit(EXIT_FAILURE);

    cout << "Введите количество студентов: ";
    cin >> n;
    cin.get();
    student * students = new student[n];

    for (int i = 0; i < n; i++)
    {
        students[i].is_repeat = false;
        cout << "Введите ФИО, дату рождения, адрес и рейтинг студента №" << i + 1 << endl;
        cin >> students[i].surname >> students[i].name >> students[i].patronymic 
            >> students[i].date_of_birth >> students[i].adress >> students[i].rating;
    }
    
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << students[i].surname << " " << students[i].name << " " << students[i].patronymic << ", "
             << students[i].date_of_birth << ", " << students[i].adress << ", " << students[i].rating << endl;
    }

    for (int i = 0; i < n; ++i) 
    {
        for (int j = i + 1; j < n; ++j) 
        {
            if (students[i].date_of_birth == students[j].date_of_birth) 
            {
                students[i].is_repeat = true;
                students[j].is_repeat = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) 
    {
        if (students[i].is_repeat = true)
            ++repeat;
    }

    student * students_ = new student[n - repeat + 1];

    int i, j = 0;
    for (i = 0, j = 0; i < n; ++i) 
    {
        if (students[i].is_repeat == false) 
        {
            students_[j] = students[i];
            cout << students[i].surname << " " << students[i].name << " " << students[i].patronymic << ", "
                 << students[i].date_of_birth << ", " << students[i].adress << ", " << students[i].rating << endl;
            j++;
        }      
    }   

    cout << "Введите фамилию человека, перед которым надо поставить другого: ";
    cin >> surname;

    for (int i = 0; i < n; i++) 
    {
        if (students[i].surname == surname) 
        {
            surname_index = i;  
            is_found = true;  
        }
    }

    if (is_found == true) 
    {                                                
        for (int i = n - 1; i > surname_index; i--)  // Исправлено здесь
        {
            students[i] = students[i - 1];                                               
        }                                               
        cout << "Введите ФИО, дату рождения, адрес, рейтинг нового студента: " << endl;
        cin >> students_[surname_index].surname >> students_[surname_index].name 
            >> students_[surname_index].patronymic >> students_[surname_index].date_of_birth 
            >> students_[surname_index].adress >> students_[surname_index].rating;
    }

    for (int i = 0; i < n - repeat + 1; i++)
    {
        File << students_[i].surname << " " << students_[i].name << " " << students_[i].patronymic << ", "
             << students_[i].date_of_birth << ", " << students_[i].adress << ", " << students_[i].rating << endl;
    }

    delete [] students;
    delete [] students_;
    return 0;
}