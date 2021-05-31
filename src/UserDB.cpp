#include "../include/UserDB.h"

User defaultUser("admin", "i<3c++",true);

UserDB::UserDB() {
    this->users.pushBack(defaultUser);
}

void UserDB::login(bool& admin, bool& logged) {
    system("cls");
    Draw::gotoxy(15, 7);

    if (logged)
    {
        logged = false;
        std::cout << "\n";
        std::cout << "Logout successfuly! Returning to main menu in 3 seconds!";
        Sleep(3000);
        return;
    }

    String temp;
    char ch;
    char pass[25];
    const char BACKSPACE = 8;
    const char RETURN = 13;
    int i = 0;
    std::cout << "Enter username:";
    std::cin >> temp;

    Draw::gotoxy(15, 9);
    std::cout << "Enter password:";
    while (ch != RETURN)
    {
        ch = getch();
        if (ch != RETURN && ch != BACKSPACE)
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
        if (ch == BACKSPACE && i > 0)
        {
            --i;
            std::cout << "\b \b";
            continue;
        }
    }
    pass[i] = '\0';

    User temp_user;

    temp_user.setUsername(temp);
    temp = pass;

    temp_user.setPass(temp);

    if (users.isExist(temp_user))
    {
        logged = true;
        std::cout << "\n";
        std::cout << "Login successfuly! Returning to main menu in 3 seconds!";
        Sleep(3000);
        return;
    }
    else
    {
        logged = false;
        std::cout << "Incorrect credentials! Returning to main menu!";
        Sleep(3000);
        return;
    }
}