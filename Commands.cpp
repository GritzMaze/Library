#include "Commands.h"

#define HEADER "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"
#define BODYLEFT "\xDB\xDB\xDB\xDB\xB2"
#define BODYRIGHT "\xB2\xDB\xDB\xDB\xDB"
#define FOOTER "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"

COORD coord = {0, 0};
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Commands::Commands()
{
    User temp("admin", "i<3c++", true);
    this->currentUser = temp;
    this->isLogged = false;
}

void Commands::choice()
{
    switch (getch())
    {
    case '1':
        //addbooks();
        printf("adding book");
        break;
    case '2':
        //deletebooks();
        printf("deleting book");
        break;
    case '3':
        //searchbooks();
        printf("searching for book");
        break;
    case '4':
        //editbooks();
        printf("Editing book");
        break;
    case '5':
        //viewbooks();
        printf("viewing book");
        break;
    case '6':
        login();
        //printf("Login book");
        break;
    case '7':
    {
        system("cls");
        gotoxy(18, 3);
        std::cout << "\tLibrary";
        gotoxy(18, 4);
        std::cout << "\tMini Project in C++";
        gotoxy(18, 5);
        std::cout << "\tis brought to you by";
        gotoxy(18, 7);
        std::cout << "\tVesselin Jivkov";
        gotoxy(16, 8);
        std::cout << "******************************************";
        gotoxy(16, 10);
        std::cout << "*******************************************";
        gotoxy(16, 11);
        std::cout << "*******************************************";
        gotoxy(16, 13);
        std::cout << "********************************************";
        gotoxy(10, 17);
        std::cout << "Exiting in 3 second...........>";
        Sleep(3000);
        exit(0);
    }
    default:
    {
        gotoxy(10, 23);
        std::cout << "\aWrong Entry! Please re-entered correct option! Press ANY key to continue...";
        if (getch())
            mainmenu();
    }
    }
}

void Commands::start()
{
    system("cls");
    char title[25] = "Library mini project";
    gotoxy(10, 4);
    for (int j = 0; j < 20; j++)
    {
        Sleep(50);
        std::cout << "*";
    }
    for (int j = 0; j < 20; j++)
    {
        Sleep(50);
        std::cout << title[j];
    }
    for (int j = 0; j < 20; j++)
    {
        Sleep(50);
        std::cout << "*";
    }
    gotoxy(10, 10);
    gotoxy(20, 7);
    char author[30] = "Created by Vesselin Jivkov";
    for (int j = 0; j < 30; j++)
    {
        Sleep(50);
        std::cout << author[j];
    }
    gotoxy(15, 10);
    std::cout << "Press any key to countinue...";
    getch();
    mainmenu();
}

void Commands::mainmenu()
{

    system("cls"); // Clear the console

    // Opening the Main Menu
    gotoxy(20, 3);
    std::cout << HEADER << " MAIN MENU " << HEADER;
    gotoxy(20, 5);
    std::cout << BODYLEFT << " COMMAND/ACTION   ";
    std::cout << "\t\t INFO   ";
    gotoxy(90, 5);
    std::cout << BODYRIGHT;
    gotoxy(20, 7);
    std::cout << BODYLEFT << " 1. ADD BOOKS   ";
    std::cout << "\t\t Add a book to the library.";
    gotoxy(90, 7);
    std::cout << BODYRIGHT;
    gotoxy(20, 9);
    std::cout << BODYLEFT << " 2. DELETE BOOKS  ";
    std::cout << " \t\t Remove a book from the library.";
    gotoxy(90, 9);
    std::cout << BODYRIGHT;
    gotoxy(20, 11);
    std::cout << BODYLEFT << " 3. SEARCH BOOKS  ";
    std::cout << "\t\t Search for a book in the library.";
    gotoxy(90, 11);
    std::cout << BODYRIGHT;
    gotoxy(20, 13);
    std::cout << BODYLEFT << " 4. EDIT BOOKS    ";
    std::cout << "\t\t Edit a book in the library.";
    gotoxy(90, 13);
    std::cout << BODYRIGHT;
    gotoxy(20, 15);
    std::cout << BODYLEFT << " 5. VIEW BOOK LIST    ";
    std::cout << "\t\t View the books in the library.";
    gotoxy(90, 15);
    std::cout << BODYRIGHT;
    gotoxy(20, 17);
    std::cout << BODYLEFT << " ";
    (isLogged ? std::cout << "6. LOGOUT    \t\t\t Logout from the account." : std::cout << "6. LOGIN   \t\t\t Sign in the account.");
    gotoxy(90, 17);
    std::cout << BODYRIGHT;
    gotoxy(20, 19);
    std::cout << BODYLEFT << " 7. CLOSE APPLICATION";
    std::cout << "\t\t Exits the application.";
    gotoxy(90, 19);
    std::cout << BODYRIGHT;
    gotoxy(20, 21);
    std::cout << FOOTER << FOOTER << "\xB2";
    gotoxy(20, 23);
    std::cout << "Enter your choice:";
    this->choice();
}

void Commands::login()
{
    system("cls");
    gotoxy(15, 7);

    String temp;
    char ch, pass[25];
    int i = 0;
    std::cout << currentUser.getUsername();
    std::cout << "Enter username:";
    std::cin >> temp;

    if (temp == currentUser.getUsername())
    {

        gotoxy(15, 9);
        std::cout << "Enter password:";
        while (ch != 13)
        {
            ch = getch();

            if (ch != 13 && ch != 8)
            {
                putch('*');
                pass[i] = ch;
                i++;
            }
        }
        pass[i] = '\0';
        if (currentUser.getPassword() == pass)
        {
            this->isLogged = true;
            std::cout << "Login successfuly! Returning to main menu in 3 seconds!";
            Sleep(3000);
            mainmenu();
        }
        else
        {
            std::cout << "Incorrect password! Returning to main menu!";
            Sleep(3000);
            mainmenu();
        }
    }
    else {
        std::cout << "No user is matching this name! Returning to main menu!";
        Sleep(3000);
        mainmenu();
    }
}