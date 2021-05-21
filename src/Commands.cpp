#include "../include/Commands.h"



Commands::Commands()
{
    User temp("admin", "i<3c++", true);
    this->currentUser = temp;
    this->users.pushBack(currentUser);
    this->isLogged = false;
}

void Commands::choice()
{
    switch (getch())
    {
    case '1':
        //addbooks();
        std::cout << "adding book";
        break;
    case '2':
        //deletebooks();
        std::cout << "deleting book";
        break;
    case '3':
        //searchbooks();
        std::cout << "searching for book";
        break;
    case '4':
        //editbooks();
        std::cout << "Editing book";
        break;
    case '5':
        //viewbooks();
        std::cout << "viewing book";
        break;
    case '6':
        login();
        //std::cout << "Login book";
        break;
    case '7':
    {
        close();
        break;
    }
    case '8':
    {
        if (!(currentUser.isAdmin() && this->isLogged))
        {
            Draw::gotoxy(10, 23);
            std::cout << "\aWrong Entry! Please re-entered correct option! Press ANY key to continue...";
            if (getch())
            {
                mainmenu();
            }
        }
        else
            std::cout << "Admun panel";
        //else admin_panel();
        //mainmenu();
        break;
    }
    default:
    {
        Draw::gotoxy(10, 25);
        std::cout << "\aWrong Entry! Please re-entered correct option! Press ANY key to continue...";
        if (getch())
            mainmenu();
        break;
    }
    }
}

void Commands::start()
{
    Draw::drawStart();
    getch();
    mainmenu();
}

void Commands::mainmenu()
{
    Draw::drawMenu(this->isLogged, this->currentUser.isAdmin());
    
    std::cout << "Enter your choice:";
    this->choice();
}

void Commands::close()
{
    Draw::drawExit();
}

void Commands::login()
{
    system("cls");
    Draw::gotoxy(15, 7);

    if (this->isLogged)
    {
        this->isLogged = false;
        std::cout << "\n";
        std::cout << "Logout successfuly! Returning to main menu in 3 seconds!";
        Sleep(3000);
        mainmenu();
    }

    String temp;
    char ch;
    // Vector<char> pass;
    char pass[25];
    int i = 0;
    std::cout << "Enter username:";
    std::cin >> temp;

    Draw::gotoxy(15, 9);
    std::cout << "Enter password:";
    while (ch != 13)
    {
        ch = getch();
        // if(ch == 8) {
        //     --i;
        //     printf('\b');
        //     continue;
        // }
        if (ch != 13 && ch != 8)
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';

    User temp_user;

    temp_user.setUsername(temp);
    temp = pass;

    temp_user.setPass(temp);

    if (users.isExist(temp_user))
    {
        this->isLogged = true;
        std::cout << "\n";
        std::cout << "Login successfuly! Returning to main menu in 3 seconds!";
        Sleep(3000);
        mainmenu();
    } else
    {
        std::cout << "Incorrect credentials! Returning to main menu!";
        Sleep(3000);
        mainmenu();
    }
}