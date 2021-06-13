#include "../include/UserDB.h"

void UserDB::add()
{
    system("cls");
    User *user = new User();
    String temp;
    char ch;
    char admin = 'n';
    const char RETURN = 13;
    Draw::drawHeader("ADD A USER");
    Draw::gotoxy(20, 19);
    Draw::drawFooter(21);
    Draw::gotoxy(20, 5);
    std::cout << "Username: ";
    std::cin >> temp;
    user->setUsername(temp);
    Draw::gotoxy(20, 7);
    std::cout << "Password: ";
    temp = temp.inputProtected();
    user->setPass(temp);
    Draw::gotoxy(20, 9);
    std::cout << "Admin rights (Y/N): ";
    std::cin >> ch;
    if (ch == 'y' || ch == 'Y')
    {
        user->setAdmin(true);
    }
    else if (ch == 'n' || ch == 'N')
    {
        user->setAdmin(false);
    }
    else
        user->setAdmin(false);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    users.pushBack(user);
    system("cls");
    Draw::gotoxy(15, 7);
    std::cout << "Entry Successful!";
    Draw::gotoxy(15, 9);
    std::cout << "Press ANY key to continue...";
    getch();
}

void UserDB::addUser()
{
    add();
}