#include "../include/Commands.h"

void Commands::saveDB()
{
    String filename;
    system("cls");
    Draw::drawHeader("DATABASE");
    Draw::gotoxy(20, 19);
    Draw::drawFooter(21);
    Draw::gotoxy(20, 10);
    std::cout << "Enter a name or a path(withouth ext): ";
    std::cin >> filename;
    users.save(filename);
    books.save(filename);
}