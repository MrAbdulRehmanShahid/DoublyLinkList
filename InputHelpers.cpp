// Implements validated integer input and stop creation.
#include "InputHelpers.h"

#include <iostream>
#include <limits>

using namespace std;

int ReadInt(const string& prompt)
{
    int v;
    while (true)
    {
        cout << prompt;
        if (cin >> v)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return v;
        }
        if (cin.eof()) return 0;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number.\n";
    }
}

Stop* ReadStop()
{
    int id = ReadInt("Enter stop ID: ");
    string name;
    cout << "Enter stop name: ";
    getline(cin, name);
    return new Stop(id, name);
}
