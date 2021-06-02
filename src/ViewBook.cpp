#include "../include/BookDB.h"


void BookDB::view()
{
    system("cls");
    Draw::drawHeader("BOOK LIST");
    Draw::drawSubmenu("TITLE", "AUTHOR", "GENRE", "ID");
    int size = books.getSize();
    int i = 0;
    for (; i < size; ++i)
    {
        books[i]->partlyPrintVertical(7 + i);
    }
    if (i < 10)
    {
        i = 10;
    }
    Draw::drawFooter(i + 2);
    Draw::gotoxy(20, i + 4);
    std::cout << "Enter 0 to go back to Main Menu.";
    Draw::gotoxy(20, i + 5);
}

void BookDB::viewBooks()
{
    view();
    std::cout << "Enter ID to see full info about a book: ";
    int id = 0;
    std::cin >> id;
    if (std::cin.fail())
    {
        InputHandle::errMsg("Not a number entered for ID!");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        viewBooks();
    }
    if (id == 0)
        return;
    if (this->printByID(id))
    {
        Draw::gotoxy(20, 23);
        std::cout << "Press ANY key to continue...";
        if (getch())
        {
            system("cls");
            viewBooks();
        }
    }
    viewBooks();
    return;
}