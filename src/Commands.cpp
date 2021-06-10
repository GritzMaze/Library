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
        deleteBooks();
        break;
    case '3':
        searchBooks();
        break;
    case '4':
        sortBooks();
        break;
    case '5':
        viewBooks();
        break;
    case '6':
        login();
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
            Draw::pressAny(23);
            if (getch())
            {
                mainmenu();
            }
        }
        else
        adminPanel();
        break;
    }
    default:
    {
        Draw::pressAny(25);
        if (getch())
            mainmenu();
        break;
    }
    }
}

void Commands::admin_choice()
{
    switch (getch())
    {
    case '1':
        users.addUser();
        adminPanel();
        break;
    case '2':
        users.deleteUser();
        adminPanel();
        break;
    case '3':
        users.viewUsers();
        adminPanel();
        break;
    case '4':
        openDB();
        adminPanel();
        break;
    case '5':
        saveDB();
        adminPanel();
        break;
    case '6':
        mainmenu();
        break;
    default:
    {
        Draw::pressAny(25);
        if (getch())
            adminPanel();
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
    users.login(this->isAdmin, this->isLogged);
    mainmenu();
}

void Commands::addBooks()
{
    system("cls");
    books.add();
    mainmenu();
}

void Commands::viewBooks()
{
    books.viewBooks();
    mainmenu();
}

void Commands::deleteBooks()
{
    books.deleteBooks();
    mainmenu();
}

void Commands::searchBooks() {
    books.search();
    mainmenu();
}

void Commands::sortBooks() {
    books.sortBooks();
    mainmenu();
}

void Commands::adminPanel() {
    Draw::drawAdminMenu();
    std::cout << "Enter your choice:";
    admin_choice();
    adminPanel();
}