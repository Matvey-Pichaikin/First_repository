#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    fstream file_1;
    fstream file_2;

    file_1.open("file_1.txt");
    file_2.open("file_2.txt");
    
    string line;
    
    while (getline(file_1, line))
    {
        int word_count = 0;
        bool flag = false;

        for (int i = 0; i < line.size();)
        {
            if (line[i] == ' ' || line[i] == '!' || line[i] == '?' || line[i] == ';' ||
                line[i] == ':' || line[i] == '.' || line[i] == ',')
            {
                word_count++;
                i++;
                while (line[i] == ' ' || line[i] == '!' || line[i] == '?' || line[i] == ';' ||
                       line[i] == ':' || line[i] == '.' || line[i] == ',')
                {
                    i++;
                }
            }
            else
            {
                i++;
            }
        }

        string * words_in_line = new string[word_count];

        int k = 0;

        for (int i = 0; i < line.size();)
        {
            if (line[i] == ' ' || line[i] == '!' || line[i] == '?' || line[i] == ';' ||
                line[i] == ':' || line[i] == '.' || line[i] == ',')
            {
                i++;
                while (line[i] == ' ' || line[i] == '!' || line[i] == '?' || line[i] == ';' ||
                       line[i] == ':' || line[i] == '.' || line[i] == ',')
                {
                    i++;
                }
                k++;
            }
            else
            {
                words_in_line[k] += line[i];
                i++;
            }
        }

        for (int i = 0; i < word_count && !flag; i++)
        {
            for (int j = 0; j < word_count && !flag; j++)
            {
                if (i != j && words_in_line[i] == words_in_line[j])
                {
                    flag = true;
                }
            }
        }

        int index_max_digit = 0;
    int number_max_digit = 0;

    for (int i = 0; i < word_count; i++)
    {
        int amount = 0;
        for (int j = 0; j < words_in_line[i].size(); j++)
        {
            if (isdigit(words_in_line[i][j]))
                amount++;
        }

        if (amount > number_max_digit)
        {
            number_max_digit = amount;
            index_max_digit = i;
        }    
    }

    if (flag)
    {
        file_2 << line << endl;
        if (number_max_digit > 0)
        {
            cout << "Word with maximum digit value: " << words_in_line[index_max_digit] << endl;
        }
        else
        {
            cout << "There are no words with numbers" << endl;
        }
    }
        delete[] words_in_line;
    } 
    
    cout << "End of file reached" << endl;
    file_1.close();
    file_2.close();
    return 0; 
}