#include "../include/Draw.h"

#define HEADER "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"
#define BODYLEFT "\xDB\xDB\xDB\xDB\xB2"
#define BODYRIGHT "\xB2\xDB\xDB\xDB\xDB"
#define FOOTER "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"

void Draw::drawMenu(const bool &isLogged, const bool& isAdmin) {
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
    if (isLogged && isAdmin)
    {
        gotoxy(20, 21);
        std::cout << BODYLEFT << " 8. ADMIN PANEL";
        std::cout << "\t\t Managing all the users.";
        gotoxy(90, 21);
        std::cout << BODYRIGHT;
        gotoxy(20, 23);
        std::cout << FOOTER << FOOTER << "\xB2";
        gotoxy(20, 25);
    }
    else
    {
        gotoxy(20, 21);
        std::cout << FOOTER << FOOTER << "\xB2";
        gotoxy(20, 23);
    }
}

void Draw::gotoxy(const int& x,const int& y)
{
    static COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Draw::drawStart() {
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
}

void Draw::drawExit() {
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