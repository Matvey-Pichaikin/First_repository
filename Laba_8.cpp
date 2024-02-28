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
    float rating;
};

int main()
{
    const int NUMBERS = 10;

    student student_1 = {"Andreeva", "Olga", "Ivanovna", "12.04.1976", 4.4};
    student student_2 = {"Petrov", "Ivan", "Sergeevich", "15.06.1995", 3.4};
    student student_3 = {"Smirnova", "Ekaterina", "Dmitrievna", "03.11.2001", 4.1};
    student student_4 = {"Kozlov", "Maxim", "Alexandrovich", "28.07.2003", 3.5};
    student student_5 = {"Ivanova", "Anastasia", "Petrovna", "12.04.1976", 2.6};
    student student_6 = {"Sokolov", "Denis", "Andreevich", "15.06.1995", 4.7};
    student student_7 = {"Morozova", "Tatyana", "Vladimirovna", "02.06.1979", 4.6};
    student student_8 = {"Lebedev", "Artem", "Nikolaevich", "12.08.1976", 5.0};
    student student_9 = {"Kuznetsova", "Anastasia", "Viktorovna", "12.12.1999", 4.3};
    student student_10 = {"Vasiliev", "Igor", "Viktorovich", "23.04.1987", 2.4};

    vector<student> students(NUMBERS);

    students[0] = student_1;
    students[1] = student_2;
    students[2] = student_3;
    students[3] = student_4;
    students[4] = student_5;
    students[5] = student_6;
    students[6] = student_7;
    students[7] = student_8;
    students[8] = student_9;
    students[9] = student_10;

    ofstream File;
    File.open("Students.txt");

    if (!File.is_open())
        exit(EXIT_FAILURE);

    cout << "Enter the surname of the person you want to precede: ";
    string surname;
    cin >> surname;

    bool is_found = false;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].surname == surname) { 
            student temp;
            cout << "Enter new student information: ";
            cin >> temp.surname >> temp.name >> temp.patronymic >> temp.date_of_birth >> temp.rating;
            students.insert(students.begin() + i, temp);
            is_found = true;
            break;
        }
    }

    if (!is_found) {
        cout << "There is no student with this surname ";
    }

    for (int i = 0; i < students.size(); i++) {
        for (int j = i + 1; j < students.size(); j++) {
            if (students[i].date_of_birth == students[j].date_of_birth) {
                students.erase(students.begin() + i);
                students.erase(students.begin() + j - 1);
                i--;
            }
        }
    }

    for (int i = 0; i < students.size(); i++) {
        File << i + 1 << ". " << students[i].surname << " " << students[i].name << " " << students[i].patronymic << ", "
             << students[i].date_of_birth << ". Rating: "  << students[i].rating << endl;
    }

    File.close();
    
    return 0;
}