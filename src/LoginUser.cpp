#include "../include/UserDB.h"

void UserDB::login(bool &admin, bool &logged)
{
    system("cls");
    Draw::gotoxy(15, 7);

    if (logged)
    {
        logged = false;
        admin = false;
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
    String username;
    String password;
    std::cout << "Enter username:";
    std::cin >> username;

    Draw::gotoxy(15, 9);
    std::cout << "Enter password:";
    //temp.inputProtected();
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

    User *temp_user = new User;
    temp_user->setUsername(username);
    password = pass;
    temp_user->setPass(password);

    if (users.isExistUser(temp_user))
    {
        logged = true;
        admin = temp_user->isAdmin();
        std::cout << "\n";
        std::cout << "Login successfuly! Returning to main menu in 3 seconds!";
        delete temp_user;
        Sleep(3000);
        return;
    }
    else
    {
        logged = false;
        admin = false;
        std::cout << "\n";
        std::cout << "Incorrect credentials! Returning to main menu!";
        delete temp_user;
        Sleep(3000);
        return;
    }
}