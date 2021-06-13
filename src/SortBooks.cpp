#include "../include/BookDB.h"

void BookDB::sortBooks()
{
    system("cls");
    Draw::drawHeader("SORT BOOK");
    Draw::drawMenuElem("SORT BY: ", "", 5);
    Draw::drawMenuElem("1. TITLE", "", 7);
    Draw::drawMenuElem("2. AUTHOR", "", 9);
    Draw::drawMenuElem("3. YEAR", "", 11);
    Draw::drawMenuElem("4. RATING", "", 13);
    Draw::drawMenuElem("5. BACK TO MAIN MENU", "", 15);
    Draw::drawFooter(17);
    Draw::gotoxy(20, 19);
    std::cout << "Enter your choice:";
    sortChoice();
}

void BookDB::sortBy(const String &choice)
{
    system("cls");
    Draw::drawHeader("SORT BOOK");
    Draw::drawMenuElem("SORT BY: ", "", 5);
    Draw::drawMenuElem("1. ASCENDING", "", 7);
    Draw::drawMenuElem("2. DESCENDING", "", 9);
    Draw::drawMenuElem("3. GO BACK", "", 11);
    Draw::drawFooter(13);
    Draw::gotoxy(20, 15);
    std::cout << "Enter your choice:";
    sortChoice2(choice);
}

void BookDB::sortChoice()
{
    switch (getch())
    {
    case '1':
        sortBy("title");
        break;
    case '2':
        sortBy("author");
        break;
    case '3':
        sortBy("year");
        break;
    case '4':
        sortBy("rating");
        break;
    case '5':
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

void BookDB::sortChoice2(const String &choice)
{
    switch (getch())
    {
    case '1':
        sortCross(choice, "asc");
        break;
    case '2':
        sortCross(choice, "desc");
        break;
    case '3':
        sortBooks();
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

void BookDB::sortCross(const String &choice, const String &option)
{
    if (choice == "year")
    {
        sortByYear(option);
    }
    else if (choice == "rating")
    {
        sortByRating(option);
    }
    else if (choice == "title")
    {
        sortByTitle(option);
    }
    else if (choice == "author")
    {
        sortByAuthor(option);
    }
    system("cls");
    Draw::gotoxy(15, 7);
    std::cout << "Books sorted Successful!";
    Draw::gotoxy(15, 9);
    std::cout << "Press ANY key to continue...";
    getch();
}

void BookDB::sortByYear(const String &direct)
{
    int size = books.getSize();
    for (int i = 0; i < size - 1; i++)

        for (int j = 0; j < size - i - 1; j++)
        {
            int elem1 = books[j]->getYOP();
            int elem2 = books[j + 1]->getYOP();
            int k = j + 1;
            if (direct == "asc" && elem1 > elem2)
            {
                books.swap(books[j], books[k]);
            }
            else if (direct == "desc" && elem1 < elem2)
            {
                books.swap(books[j], books[k]);
            }
        }
}

void BookDB::sortByRating(const String &direct)
{
    int size = books.getSize();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            double elem1 = books[j]->getRating();
            double elem2 = books[j + 1]->getRating();
            int k = j + 1;
            if (direct == "asc" && elem1 > elem2)
            {
                books.swap(books[j], books[k]);
            }
            else if (direct == "desc" && elem1 < elem2)
            {
                books.swap(books[j], books[k]);
            }
        }
    }
}

void BookDB::sortByTitle(const String &direct)
{
    int size = books.getSize();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            String elem1 = books[j]->getTitle();
            String elem2 = books[j + 1]->getTitle();
            int k = j + 1;
            if (direct == "asc" && elem1 > elem2)
            {
                books.swap(books[j], books[k]);
            }
            else if (direct == "desc" && elem1 < elem2)
            {
                books.swap(books[j], books[k]);
            }
        }
    }
}

void BookDB::sortByAuthor(const String &direct)
{
    int size = books.getSize();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            String elem1 = books[j]->getAuthor();
            String elem2 = books[j + 1]->getAuthor();
            int k = j + 1;
            if (direct == "asc" && elem1 > elem2)
            {
                books.swap(books[j], books[k]);
            }
            else if (direct == "desc" && elem1 < elem2)
            {
                books.swap(books[j], books[k]);
            }
        }
    }
}
