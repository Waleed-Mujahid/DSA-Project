#include <iostream>
#include "datatype.hpp"
#include "AVL_Tree.cpp"
#include "trie.cpp"
#include "functions.cpp"
#include <chrono>
#include "tempFile.cpp"

using namespace std;

int main()
{
    searchEngine obj;
    obj.readData();
    char dec, c;
    int count, type;
    string str;
    cout << "Welcome to Courses search Engine. \nYou can browse Udemy and Coursera courses.\n"
         << endl;
    do
    {
        cout << "Press any key to continue.  .  .\n";
        cout << "At any moment Press Q to quit: ";
        cin >> dec;

        if (dec == 'q' || dec == 'Q')
            break;
        else
        {
            cout << endl;
            cin.sync();
            cout << "1. Press 1 or T to search via keywords." << endl;
            cout << "2. Press 2 or S to search category-wise." << endl;
            cout << "3. Press 3 or F to browse free courses." << endl;
            cout << "4. Press 4 or E to search exact course names." << endl;
            cout << "5. Press 5 or A to use autocomplete." << endl;
            cout << "Press q to Quit." << endl;
            c = getchar();
            switch (toupper(c))
            {
            case 'T':
            case '1':
                cin.sync();
                cout << "Please enter a keyword that you wish to search" << endl;
                cin >> str;
                cout << endl;
                obj.browseCourses(str);
                break;
            case 'S':
            case '2':
                cin.sync();
                cout << "Please enter a Category that you wish to search" << endl;
                obj.searchCategoryWise();
                break;
            case 'F':
            case '3':
                cout << "Enter the number of courses to be returned: ";
                cin >> count;
                cin.sync();
                cout << "Press any key to continue .   .   .\n";
                cout << "Press 1 for just course names: ";
                cin >> type;
                cout << endl;
                if (type == 1)
                    obj.searchFreeCourses(count, 1);
                else
                    obj.searchFreeCourses(count, 0);
                break;

            case 'E':
            case '4':
                cin.sync();
                obj.searchExactCourse();
                break;
            case 'Q':
                dec = 'Q';
                break;
            case 'A':
            case '5':
                cin.sync();
                obj.autoComplete();
                break;
            default:
                cout << "Invalid input" << endl;
            }

        }
    } while (toupper(dec) != 'Q');
}