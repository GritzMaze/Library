#include "../include/Commands.h"

void Commands::openDB() {
    String text;
    system("cls");
    Draw::drawHeader("DATABASE");
    Draw::gotoxy(20, 19);
    Draw::drawFooter(21);
    Draw::gotoxy(20, 10);
    std::cout << "Enter a DB to open (Just the name): ";
    std::cin >> text;
    books.open(text);
    users.open(text);
}