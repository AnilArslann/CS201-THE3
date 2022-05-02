#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <algorithm>
using namespace std;
bool question_mark_search(string search_string)
{
    if (search_string.find("?") != string::npos)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool lower_case_checker(string text)
{

    int checker = 0;
    for (int i = 0; i < text.length(); i++)
    {
        if ((text.at(i) >= 'a' && text.at(i) <= 'z') || question_mark_search(text) == false)
        {
            checker += 1;
        }
    }
    if (checker == text.length())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool source_string_checker(string source_string)
{
    if (source_string.length() == 0 || source_string.find("?") != string ::npos || lower_case_checker(source_string) == false)
    {
        cout << "Wrong input format! Try again.\n"
             << endl;
        return false;
    }
    else
    {
        return true;
    }
}

bool search_string_checker(string search_string, string source_string)
{
    int length = search_string.length();
    int wildcard_checker = 0;
    for (int i = 0; i < search_string.length(); i++)
    {
        if (search_string.at(i) == '?')
        {
            wildcard_checker += 1;
        }
    }
    if (search_string.length() == 0 || length > source_string.length() || lower_case_checker(search_string) == false || wildcard_checker == length)
    {
        cout << "Wrong input format! Try again.";
        return false;
    }
    else
    {
        return true;
    }
}

void searching_process(string search_string, string source_string)
{
    int counter = 0;
    cout << "For the source word \"" << source_string << "\" and search word \"" << search_string << "\",";
    for (int j = 0; j < source_string.length(); j++)
    {

        string change_search = search_string;
        for (int k = 0; k < search_string.length(); k++)
        {
            if (search_string.at(k) == '?')
            {

                change_search[k] = source_string[k + j];
            }
        }

        if (change_search == source_string.substr(j, search_string.length()))
        {

            cout << "\n\"" << change_search << "\" has been found at index " << j;
            counter++;
        }
    }
    if (counter == 0)
    {
        cout << " no match has been found.";
    }
}

int main()
{

    cout << "This program searches a search string in a source string with the option of wildcards." << endl;
    cout << "\nExample inputs with their meaning in parentheses:" << endl;
    cout << "1 thislectureisawesome (to enter a new source string)" << endl;
    cout << "2 lecture (to enter a new search string)" << endl;
    cout << "2 t?r? (to enter a search string with wildcards)  " << endl;
    cout << "3 (to exit the program)" << endl;
    cout << endl;

    string source_string;
    string search_string;

    while (true)
    {

        cout << "Enter your choice and string: ";

        string selection;
        cin >> selection;

        if (selection == "1")
        {

            cin >> source_string;
            if (source_string_checker(source_string) == true)
            {
                cout << "Source word has been changed to \"" << source_string << "\"" << endl;
                cout << endl;
            }
        }
        else if (selection == "2")
        {
            cin >> search_string;

            if (search_string_checker(search_string, source_string) == true)
            {

                searching_process(search_string, source_string);
            }

            cout << "\n"
                 << endl;
        }

        else if (selection == "3")
        {
            cout << "See you!" << endl;
            break;
        }
        else
        {

            cout << "Choice can be 1, 2 or 3! Try again.\n"
                 << endl;
        }
    }
    return 0;
}