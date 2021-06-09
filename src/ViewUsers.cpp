#include "../include/UserDB.h"

void UserDB::view()
{
    system("cls");
    Draw::drawHeader("USER LIST");
    Draw::drawSubmenu("USERNAME", "", "ADMIN RIGHTS", "ID");
    int size = users.getSize();
    int i = 0;
    for (; i < size; ++i)
    {
        users[i]->printVertical(7+i);
    }
    if (i < 10)
    {
        i = 10;
    }
    Draw::drawFooter(i + 2);
    Draw::gotoxy(20, i + 4);
    std::cout << "Enter 0 to go back to Main Menu.";
    Draw::gotoxy(20, i + 5);
}

void UserDB::viewUsers()
{
    view();
    std::cout << "Enter your choice: ";
    int choice = 0;
    std::cin >> choice;
    if (std::cin.fail())
    {
        InputHandle::errMsg("Not a number entered!");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        viewUsers();
    }
    if (choice == 0)
        return;

    return;
}