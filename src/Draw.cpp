#include "../include/Draw.h"

#define HEADER "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"
#define BODYLEFT "\xDB\xDB\xDB\xDB\xB2"
#define BODYRIGHT "\xB2\xDB\xDB\xDB\xDB"
#define FOOTER "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"

void Draw::drawMenu(const bool &isLogged, const bool& isAdmin) {
    system("cls"); // Clear the console
    // Opening the Main Menu
    drawHeader("MAIN MENU");
    drawMenuElem("COMMAND/ACTION   ", "INFO   ", 5);
    drawMenuElem("1. ADD BOOKS  ", "Add a book to the library.", 7);
    drawMenuElem("2. DELETE BOOKS  ", "Remove a book from the library.", 9);
    drawMenuElem("3. SEARCH BOOKS  ", "Search for a book in the library.", 11);
    drawMenuElem("4. SORT BOOKS  ", "Sort the books in the library.", 13);
    drawMenuElem("5. VIEW BOOK LIST  ", "View the books in the library.", 15);
    (isLogged ? drawMenuElem("6. LOGOUT  ", "Logout from the account.", 17)
              : drawMenuElem("6. LOGIN   ", "Sign in the account.", 17));
    drawMenuElem("7. CLOSE APPLICATION", "Exits the application.", 19);
    if (isLogged && isAdmin)
    {
        drawMenuElem("8. ADMIN PANEL ", "Managing all the users.", 21);
        drawFooter(23);
        gotoxy(20, 25);
    }
    else
    {
        drawFooter(21);
        gotoxy(20, 23);
    }
}

void Draw::drawMenuElem(const String& TITLE, const String& INFO = "", const int& y = 0) {
    gotoxy(20, y);
    std::cout << BODYLEFT << " " << TITLE;
    gotoxy(57, y);
    std::cout << INFO;
    gotoxy(90, y);
    std::cout << BODYRIGHT;
}

void Draw::drawSubmenu(const String& title1, const String& title2 = "", const String& title3 = "", const String& title4 = "") {
    gotoxy(20, 5);
    std::cout << title1;
    gotoxy(50, 5);
    std::cout << title2;
    gotoxy(70,5);
    std::cout << title3;
    gotoxy(90,5);
    std::cout << title4;
    // gotoxy(90, 5);
}

void Draw::drawAdminMenu() {
    system("cls");
    drawHeader("ADMIN MENU");
    drawMenuElem("COMMAND/ACTION   ", "INFO   ", 5);
    drawMenuElem("1. ADD USER  ", "Add a user.", 7);
    drawMenuElem("2. DELETE USER  ", "Delete a user.", 9);
    drawMenuElem("3. VIEW USERS  ", "View a list of users.", 11);
    drawMenuElem("4. OPEN DATABASE  ", "Open a database.", 13);
    drawMenuElem("5. SAVE DATABASE  ", "Save the database.", 15);
    drawMenuElem("6. MAIN MENU  ", "Go to the main menu.", 17);
    drawFooter(19);
    gotoxy(20, 21);
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

void Draw::drawHeader(const String& title) {
    gotoxy(20, 3);
    std::cout << HEADER << " " << title << " " << HEADER;
}

void Draw::drawFooter(const int& y) {
    gotoxy(20, y);
    std::cout << FOOTER << FOOTER << "\xB2";
}

void Draw::pressAny(const int& y) {
    gotoxy(10, y);
    std::cout << "\aWrong Entry! Please re-entered correct option! Press ANY key to continue...";
}