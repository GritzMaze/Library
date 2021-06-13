#include "../include/BookDB.h"

void BookDB::viewSearched(const String &criteria)
{
    String temp = InputHandle::inputValue();
    temp.toLower();
    system("cls");
    Draw::drawHeader("BOOK LIST");
    Draw::drawSubmenu("TITLE", "AUTHOR", "GENRE", "ID");
    int elements = 0;
    if (criteria == "title")
    {
        elements = searchByTitle(temp);
    }
    else if (criteria == "author")
    {
        elements = searchByAuthor(temp);
    }
    else
        elements = searchByByKeyword(temp);
    int k = 0;
    if (elements < 10)
        k = 10;
    else
        k = elements;

    Draw::drawFooter(k + 2);
    Draw::gotoxy(20, k + 4);
    std::cout << elements << " Books have been found matching the criteria!";
    Draw::gotoxy(20, k + 6);
    std::cout << "Press ANY key to continue...";
    getch();
}

int BookDB::searchByTitle(const String &title)
{
    int size = books.getSize();
    int counter = 0;
    String temp_title;
    for (int i = 0; i < size; ++i)
    {
        temp_title = books[i]->getTitle();
        temp_title.toLower();
        if (temp_title == title)
        {
            books[i]->partlyPrintVertical(7 + counter);
            counter++;
        }
    }
    return counter;
}

int BookDB::searchByAuthor(const String &author)
{
    int size = books.getSize();
    int counter = 0;
    String temp_author;
    for (int i = 0; i < size; ++i)
    {
        temp_author = books[i]->getAuthor();
        temp_author.toLower();
        if (temp_author == author)
        {
            books[i]->partlyPrintVertical(7 + counter);
            counter++;
        }
    }
    return counter;
}

int BookDB::searchByByKeyword(const String &keyword)
{
    int size = books.getSize();
    int counter = 0;
    for (int i = 0; i < size; ++i)
    {
        if (books[i]->getKeywords().isExist(keyword))
        {
            books[i]->partlyPrintVertical(7 + counter);
            counter++;
        }
    }
    return counter;
}

void BookDB::searchChoice()
{
    switch (getch())
    {
    case '1':
        viewSearched("title");
        break;
    case '2':
        viewSearched("author");
        break;
    case '3':
        viewSearched("keyword");
        break;
    case '4':
        break;
    default:
    {
        Draw::pressAny(25);
        if (getch())
            search();
        break;
    }
    }
}

void BookDB::search()
{

    system("cls");
    Draw::drawHeader("FIND BOOK");
    Draw::drawMenuElem("SEARCH BY: ", "", 5);
    Draw::drawMenuElem("1. TITLE", "", 7);
    Draw::drawMenuElem("2. AUTHOR", "", 9);
    Draw::drawMenuElem("3. KEYWORD", "", 11);
    Draw::drawMenuElem("4. BACK TO MAIN MENU", "", 13);
    Draw::drawFooter(15);
    Draw::gotoxy(20, 17);
    std::cout << "Enter your choice:";
    searchChoice();
}