// Implements the bus route menu display and command loop.
#include "Menu.h"

#include "InputHelpers.h"

#include <iostream>

using namespace std;

void ShowMenu()
{
    cout << "\n===== Bus Route Stop Manager =====\n"
         << " 1. Show current stop\n"
         << " 2. Move to next stop\n"
         << " 3. Move to previous stop\n"
         << " 4. Insert new stop after current stop\n"
         << " 5. Remove current stop (closed)\n"
         << " 6. Move current stop one position toward route end\n"
         << " 7. Move current stop one position toward route start\n"
         << " 8. Display route outbound (first to last)\n"
         << " 9. Display route inbound (last to first)\n"
         << "10. Exit\n";
}

void RunMenu(BusRoute& route)
{
    int choice;
    do
    {
        ShowMenu();
        choice = ReadInt("Enter your choice: ");

        switch (choice)
        {
        case 1: route.PrintCurrent(); break;
        case 2: route.Next();     route.PrintCurrent(); break;
        case 3: route.Previous(); route.PrintCurrent(); break;
        case 4:
            route.InsertAfterCurrent(ReadStop());
            cout << "New stop added after the current stop.\n";
            break;
        case 5:
        {
            Stop* removed = route.RemoveCurrent();
            if (removed != nullptr)
            {
                cout << "Removed stop: " << removed->stopID << " - "
                     << removed->name << endl;
                delete removed;
                route.PrintCurrent();
            }
            else
                cout << "Nothing to remove. The route has no stops.\n";
            break;
        }
        case 6: route.MoveCurrentRight(); break;
        case 7: route.MoveCurrentLeft();  break;
        case 8: route.PrintOutbound(); break;
        case 9: route.PrintInbound();  break;
        case 10: cout << "Exiting. Goodbye!\n"; break;
        default: cout << "Invalid choice. Please select 1-10.\n";
        }
    } while (choice != 10 && !cin.eof());
}
