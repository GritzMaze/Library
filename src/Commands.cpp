#include "../include/Commands.h"



Commands::Commands()
{
    this->isAdmin = false;
    this->isLogged = false;
}

void Commands::choice()
{
    switch (getch())
    {
    case '1':
        addBooks();
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
        viewBooks();
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
        if (!(this->isAdmin && this->isLogged))
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
    Draw::drawMenu(this->isLogged, this->isAdmin);
    
    std::cout << "Enter your choice:";
    choice();
}

void Commands::close()
{
    Draw::drawExit();
}

void Commands::login()
{
    users.login(this->isLogged, this->isAdmin);
    mainmenu();
}

void Commands::addBooks() {
    system("cls");
    books.add();
    Sleep(3000);
    mainmenu();
}

void Commands::viewBooks() {
    system("cls");
    books.view();
    Sleep(10000);
    mainmenu();
}